
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

## How `cout`/`cin` and bitwise `<<`/`>>` share the same operator

This is worth explaining because it's the trickiest design decision in
this compiler. In real C++, `cout << a << b` and `x << a << b` (bitwise
shift) are **syntactically identical** — the compiler doesn't know which
one it is until it looks at the *type* of the left operand and picks an
`operator<<` overload. This compiler does the same thing:

- `cout`, `cin`, and `endl` are just ordinary expression atoms, parsed by
  the *same* `<<`/`>>` grammar rules as arithmetic bitwise shifts. There is
  no separate "print statement" grammar at all — `cout << a << endl;` is
  parsed as an ordinary expression statement, producing this AST:
  `((cout << a) << endl)`.
- At **runtime**, `Interpreter::evalExpr` evaluates the left side of a
  `<<`/`>>` first. If it evaluates to the special `cout`/`cin` marker
  value, the interpreter performs a print/read side effect and returns
  the *same* marker again (mirroring how `ostream::operator<<` returns
  `*this` in real C++) — that's what makes chaining (`cout << a << b`)
  work correctly. If the left side is an ordinary number, it falls
  through to normal integer bitwise shift instead.

This mirrors real C++ semantics closely and avoids inventing any
special-case grammar rules or ambiguity for `cout`/`cin`.

## Build

You need **Flex** and **Bison** (on Windows: **win_flex** / **win_bison**,
or plain `flex`/`bison` if you're using MSYS2/MinGW), plus **g++**.

> **Two build quirks you'll hit, both already handled here:**
> 1. The `%union` carries `std::string*` / `ASTNode*`, which is C++, so
>    the generated scanner/parser must be compiled **as C++**
>    (`lex.yy.cpp` / `parser.tab.cpp`, not `.c`), and `parser.y` uses a
>    `%code requires { ... }` block so the generated header pulls in
>    `ast.h` correctly.
> 2. Flex-generated code calls the POSIX function `fileno`, which strict
>    `-std=c++17` hides. We build with **`-std=gnu++17`** instead (same
>    language features, keeps that visible).
> 3. `input.cpp` is a **sample program to run through the compiler**, not
>    part of the compiler's own source — and it has its own `int main()`.
>    Never build with a `*.cpp` glob (it'll pull `input.cpp` in and you'll
>    get a "multiple definition of `main`" linker error). List the
>    compiler's source files explicitly instead, as shown below.

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
15
Greater
0 1 2
Sum of odds: 4
Flag is true and c > 5
Hello, World!
Pi is about 3.14159
mask & 3 = 2
1 << 4 = 16
```

## How this was verified

This sandbox has no internet access and neither Flex nor Bison could be
installed, so `lexer.l` / `parser.y` themselves could not be run through
the real tools here (exactly as with the Mini C Compiler before it).
What **was** verified: `input.cpp`'s AST was hand-built directly in C++
and fed straight into `semantic.cpp`, `interpreter.cpp`, `tac.cpp`,
`codegen.cpp`, and `assembly.cpp` (skipping only the scanner/parser
step). Every module compiled cleanly with `-Wall` and produced exactly
the expected output above, including correct `break`/`continue` behavior,
`string` concatenation, real C++-style `double` formatting (via genuine
`std::cout`), and correct TAC/codegen/assembly traces for every
construct in the test program (this process also caught and fixed a real
bug in the debug-view tokenizer's handling of string literals containing
spaces).

The grammar was written and re-checked by hand, reusing the same flat
`%left`/`%nonassoc` precedence style already confirmed conflict-free by
real Bison on the Mini C Compiler, extended with more precedence levels
for the added bitwise/shift operators (in the same order the real
language uses them). Still, the very first time you build this for real,
run:

```
bison -Wall -d --defines=parser.tab.h -o parser.tab.cpp parser.y
```

and read any conflict warnings it prints — if there are none, the
grammar is clean; if there are a few, tell me what they say and I'll fix
them immediately.

- Arrays, vectors, and pointers
- User-defined functions beyond `main()`
- `switch` / classes
=======
# Temp_Compiler
>>>>>>> 5c5e72851ce1897d8446c9f59497538d84013c2e
