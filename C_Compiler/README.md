# Mini C Compiler

A Flex + Bison + C++ compiler/interpreter for a subset of C, built as one
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
MiniCCompiler/
├── lexer.l              Lexical analyzer (Flex)
├── parser.y              Syntax analyzer + AST builder (Bison)
├── ast.h / ast.cpp         AST node definitions + debug printer
├── symbol_table.h / .cpp    Variable table (name, type, scope, const, value)
├── semantic.h / .cpp         Static checks (see below)
├── interpreter.h / .cpp        Tree-walking interpreter -> real program output
├── tac.h / .cpp                  Three Address Code generator (debug only)
├── codegen.h / .cpp                Pseudo target-machine instructions (debug only)
├── assembly.h / .cpp                 Pseudo x86 assembly (debug only)
├── main.cpp                            Driver / pipeline controller
├── input.c                              Sample test program (exercises every feature)
├── Makefile
└── README.md
```

## Supported C subset

- **Types:** `int`, `float`, `double`, `char`, `long` / `long long` / `long int` /
  `unsigned long long` (all 64-bit, stored as `long`)
- **`const` variables** — must be initialized; any later modification
  (`x = ...`, `x += ...`, `x++`, `scanf("...",&x)`) is a compile-time
  (semantic) error.
- **Declarations:** single or multiple per statement —
  `int a, b, c;`  `int x = 1, y = 2, z = 3;`  `const int MAX = 100;`
- **Assignment:** `a = 10;`
- **Compound assignment:** `+= -= *= /=`
- **Increment/decrement:** `++a`, `a++`, `--a`, `a--`
- **Arithmetic:** `+ - * / %` (int/long done as integer math, float/double
  promote automatically, e.g. `int + double -> double`)
- **Relational:** `> < >= <= == !=`
- **Logical:** `&& || !`
- **Bitwise:** `& | ^ ~ << >>` (integer operands only — a `float`/`double`
  operand is a semantic error)
- **Ternary:** `cond ? a : b` (short-circuit — only the taken branch runs)
- **Control flow:** `if`, `if / else`, `else if`, `while`, `do { } while`,
  `for`, `switch` (with fallthrough, `default`, and correct nesting)
- **`break` / `continue`** — work inside `for`, `while`, `do-while`, and
  (for `break`) `switch`; using either outside a loop/switch is a semantic
  error
- **`sizeof(type)`** and **`sizeof(expr)`** — `int`/`float`=4, `double`/`long`=8, `char`=1
- **`printf(...)`** with `%d %f %lf %lld %c %s %%` and escape sequences (`\n`, `\t`)
- **`scanf(...)`** with `%d %f %lf %lld %c`, reads from stdin, and raises a
  runtime error if the specifier doesn't match the variable's declared type
- **Built-in math functions:** `sqrt()`, `pow()`, `abs()`, `ceil()`, `floor()`
- **`return`**
- `#include <...>` lines are recognized and ignored (works for both
  `<stdio.h>` and `<math.h>` — the functions above are always available
  as compiler built-ins, no real header parsing needed)
- Only a single `int main() { ... }` function (no user-defined functions,
  no pointers/arrays/structs)

**Note:** every `if` / `while` / `for` / `do-while` body must use `{ }`
braces, even for a single statement (`if (x) { break; }`, not
`if (x) break;`). This is a deliberate grammar simplification that also
sidesteps the classic "dangling else" ambiguity.

## Error reporting

Every error is printed with a category, a line number (where available),
and a specific message:

```
Lexical Error:
Line 3:
Unknown character '@'.

Syntax Error:
Line 5:
syntax error, unexpected ')' (near token ')').

Semantic Error:
  Line 3: Cannot modify constant variable 'x'

Runtime Error:
Format specifier does not match variable type.
```

## Build

You need **Flex** and **Bison** (on Windows: **win_flex** / **win_bison**),
plus a C++17-capable **g++**.

> **Important:** the union used to carry token/AST values contains
> `std::string*` / `ASTNode*` / `std::vector<ASTNode*>*` pointers, so the
> generated scanner/parser must be compiled **as C++**, not as C. The
> Makefile does this by telling Flex/Bison to emit `lex.yy.cpp` /
> `parser.tab.cpp` (not the classic `.c` names) — g++ then compiles them
> as C++ automatically because of the extension.

> **Bison version note:** `parser.y` intentionally uses the classic
> `%error-verbose` directive (not the newer `%define parse.error verbose`
> spelling) so it builds cleanly on **Bison 2.4.2**, which is what
> `win_bison` (the winflexbison package) ships on Windows. If your `bison
> --version` is 2.7+ it will just print a harmless "deprecated directive"
> note and build fine either way.

### Windows (win_flex / win_bison)

```
win_bison -d --defines=parser.tab.h -o parser.tab.cpp parser.y
win_flex -o lex.yy.cpp lexer.l
g++ -std=c++17 *.cpp -o compiler.exe
```

or simply:

```
make FLEX=win_flex BISON=win_bison
```

### Linux / macOS (flex / bison)

```
make
```

which expands to:

```
bison -d --defines=parser.tab.h -o parser.tab.cpp parser.y
flex -o lex.yy.cpp lexer.l
g++ -std=c++17 *.cpp -o compiler.exe
```

### Run

```
./compiler.exe input.c            # only the program's own output
./compiler.exe input.c --debug    # every compiler phase, then the output
```

(`make run` / `make debug` do the same using the bundled `input.c`.)

`input.c` uses `scanf`, so when running it directly, either type a number
and press Enter when prompted, or pipe one in:

```
echo 20 | ./compiler.exe input.c
```

## What each module does

**lexer.l** — recognizes keywords (including `const`, `long`, `double`,
`switch`/`case`/`default`, `break`/`continue`, `do`, `sizeof`, `scanf`,
and the built-in math function names), identifiers, integer/float/char/
string literals, operators (including bitwise `& | ^ ~ << >>` and the
ternary `? :`), comments, and silently skips `#include` lines. On an
unrecognized character it reports a `Lexical Error` with line number and
stops.

**parser.y** — Bison grammar. Builds an `ASTNode*` tree as it parses;
`astRoot` (declared in `main.cpp`) ends up pointing at the finished tree.
`yyerror()` reports detailed `Syntax Error` messages (line + bison's
"unexpected X, expecting Y" detail) via `%error-verbose`.

**ast.h/.cpp** — one tagged `ASTNode` class (a `NodeType` enum says how to
read its fields) instead of one C++ class per node kind — every other
module switches on `node->type`. A statement-level multi-variable
declaration (`int a, b = 2;`) and a `{ }` block both reuse the same
`NODE_BLOCK` node, which keeps the interpreter/semantic code simple.
`printAST()` is the `--debug` tree dump.

**symbol_table.h/.cpp** — a stack of scopes (`main`, plus a fresh scope
per `for` loop) storing each variable's name/type/scope/const-ness/value.

**semantic.h/.cpp** — walks the AST *before* anything runs, checking for
undeclared variables, duplicate declarations, literal division-by-zero,
`const` violations, `break`/`continue` outside a loop or switch, and
bitwise operators applied to a `float`/`double` operand.

**interpreter.h/.cpp** — walks the AST and actually executes it: this is
the only module that produces the real program output. `break`/`continue`
are implemented as small C++ exceptions (`BreakSignal` / `ContinueSignal`)
caught by the nearest enclosing loop/switch, which naturally gives correct
nested-loop and nested-switch behavior. `switch` fallthrough is
implemented by executing every case block in source order starting at the
matched (or `default`) case, until a `break` is hit or the switch ends.

**tac.h/.cpp / codegen.h/.cpp / assembly.h/.cpp** — three more (separate)
walks over the AST that print, purely for `--debug`, three progressively
lower-level educational views of the same program: three-address code,
pseudo target instructions, and pseudo x86 assembly. These do not affect
program execution — the interpreter is what actually runs the code.

## Verified test run

`echo 20 | ./compiler.exe input.c` exercises every feature above (const,
long long, double, scanf, sizeof, multi-declaration, bitwise ops, ternary,
switch with fallthrough and nesting, break/continue in `for`/`while`/
`do-while`, and the math built-ins) and produces the expected output with
exit code 0 — no crashes, no unhandled exceptions.

## Roadmap (if you want to extend it further)

- Arrays and pointers
- User-defined functions beyond `main()`
- Real `#include` header parsing (currently `#include` lines are just
  skipped, and the math/stdio functions are recognized as built-ins)
