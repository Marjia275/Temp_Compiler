
# Mini C++ Compiler

A Flex + Bison + C++ compiler for a subset of C++, built the same way as
the Mini C Compiler before it — one Flex/Bison pair at the core, one
module per compiler phase.

```
Input Source Code
   -> Lexical Analysis   (lexer.l)
   -> Syntax Analysis    (parser.y)  -> builds the AST
   -> AST                (ast.h/.cpp)
   -> Symbol Table        (symbol_table.h/.cpp)
   -> Semantic Analysis    (semantic.h/.cpp)
   -> Interpreter            (interpreter.h/.cpp)  -> PROGRAM OUTPUT
   -> Three Address Code (TAC)  (tac.h/.cpp)
   -> Code Generation             (codegen.h/.cpp)
   -> Assembly Generation           (assembly.h/.cpp)
```

## Project structure

```
MiniCPPCompiler/
├── lexer.l              Lexical analyzer (Flex)
├── parser.y              Syntax analyzer + AST builder (Bison)
├── ast.h / ast.cpp         AST node definitions + debug printer
├── symbol_table.h / .cpp    Variable table (name, type, scope, value)
├── semantic.h / .cpp         Static checks (undeclared vars, dup decls, div/0, cin/break/continue misuse)
├── interpreter.h / .cpp        Tree-walking interpreter -> real program output
├── tac.h / .cpp                  Three Address Code generator
├── codegen.h / .cpp                Pseudo target-machine instructions
├── assembly.h / .cpp                 Pseudo x86 assembly
├── main.cpp                            Driver / pipeline controller
├── input.cpp                            Sample test program
├── Makefile
└── README.md
```

## Supported C++ subset

- Types: `int`, `float`, `double`, `char`, `bool`, `string`
- Declarations & assignment: `int a = 5;`, `a = 10;`
- Compound assignment: `+= -= *= /=` (`+=` also works for `string`, as concatenation)
- Increment/decrement: `++a`, `a++`, `--a`, `a--`
- Arithmetic: `+ - * / %` (`+` also concatenates when either side is a `string`)
- Relational: `> < >= <= == !=`
- Logical: `&& || !`
- Bitwise: `& | ^ ~ << >>`
- Control flow: `if`, `if / else`, `else if`, `while`, `for`, `break`, `continue`
- `cout << ... << endl;` and `cin >> ...;`
- `return`
- `#include <...>` and `using namespace std;` are recognized and ignored
- Only a single `int main() { ... }` function (no user-defined functions,
  no classes/pointers/arrays/STL — matches the "NOT REQUIRED" list you gave)

One simplification vs. real C++: each declaration handles **one variable
at a time** (`int a = 5; int b = 10;` — two statements — rather than
`int a = 5, b = 10;` on one line).

### Windows (win_flex / win_bison)

```
win_bison -d --defines=parser.tab.h -o parser.tab.cpp parser.y
win_flex -o lex.yy.cpp lexer.l
g++ -std=gnu++17 ast.cpp symbol_table.cpp semantic.cpp interpreter.cpp tac.cpp codegen.cpp assembly.cpp main.cpp lex.yy.cpp parser.tab.cpp -o compiler.exe
```
```

which expands to:

```
bison -d --defines=parser.tab.h -o parser.tab.cpp parser.y
flex -o lex.yy.cpp lexer.l
g++ -std=gnu++17 ast.cpp symbol_table.cpp semantic.cpp interpreter.cpp tac.cpp codegen.cpp assembly.cpp main.cpp lex.yy.cpp parser.tab.cpp -o compiler.exe
```

### Run

```
.\compiler.exe input.cpp               # only the program's own output
.\compiler.exe input.cpp --debug       # every compiler phase, then the output
```

You can also paste code straight into the terminal instead of using a file:

```
.\compiler.exe
```
Paste your C++ code, then press **Ctrl+Z, Enter** (Windows) — or **Ctrl+D**
(Linux/macOS) — on its own line to run it. `.\compiler.exe --debug` does
the same in debug mode.

(`make run` / `make debug` do the same using the bundled `input.cpp`.)

## What each module does

**lexer.l** — recognizes keywords, identifiers, numeric/char/string/bool
literals, operators, comments, and silently skips `#include` and
`using namespace std;` lines.

**parser.y** — Bison grammar. Builds an `ASTNode*` tree as it parses;
`astRoot` (declared in `main.cpp`) ends up pointing at the finished tree.

**ast.h/.cpp** — one tagged `ASTNode` class (a `NodeType` enum says how to
read its fields) instead of one C++ class per node kind — every other
module switches on `node->type`. `printAST()` is the `--debug` tree dump.

**symbol_table.h/.cpp** — a stack of scopes (`main`, plus a fresh scope
per `for` loop) storing each variable's name/type/scope/value (including
`string` values).

**semantic.h/.cpp** — walks the AST *before* anything runs, checking for
undeclared variables, duplicate declarations, literal division-by-zero,
invalid `cin >> ...` targets (must be a plain variable), and `break`/
`continue` used outside a loop.

**interpreter.h/.cpp** — walks the AST and actually executes it: this is
the only module that produces the real program output. `break`/`continue`
are implemented as C++ exceptions that unwind out of the nearest loop's
body (a `for` loop still runs its update step after a `continue`, exactly
like real C++).

**tac.h/.cpp / codegen.h/.cpp / assembly.h/.cpp** — three more (separate)
walks over the AST that print, purely for `--debug`, three progressively
lower-level educational views of the same program: three-address code,
pseudo target instructions, and pseudo x86 assembly. `break`/`continue`
become `goto` to the loop's start/end label, exactly as a real compiler
would lower them. These views do not affect execution — the interpreter
is what actually runs the code.

## Test input & expected output

`input.cpp` (bundled) exercises variables, `cout`/`endl`, `if`, `for` with
`break`, `for` with `continue`, `bool`/`&&`, `string` concatenation,
`double` formatting, and bitwise `&`/`<<`. Running
`.\compiler.exe input.cpp` prints:

```
