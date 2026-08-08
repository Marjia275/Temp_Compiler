# Team

| Name | Student ID |
|---|---|
| Ali Hussain | 231-115-170 |
| Marjia Chowdhury | 231-115-183 |

**Course Name:** Compiler Construction Lab  
**Course Code:** CSE 416  
**Institution:** Metropolitan University, Sylhet, Bangladesh  
**Batch / Section:** 58 / E  
**Supervisor:** Mahbuba Akther Liza

---

# Temp Compiler (C / C++ / Java)

An educational, browser-based compiler platform implementing three independent
Flex + Bison + C++ compilers — for a subset of **C**, **C++**, and **Java** —
sharing one architecture, plus a Node.js/Express/WebSocket backend and a
CodeMirror + xterm.js frontend for writing, running, and debugging programs
directly in the browser.

Each language compiler follows the same pipeline:

```
Source Code
  -> Lexical Analysis   (lexer.l / Flex)
  -> Syntax Analysis    (parser.y / Bison) -> builds the AST
  -> AST                (ast.h / ast.cpp)
  -> Symbol Table        (symbol_table.h / .cpp)
  -> Semantic Analysis   (semantic.h / .cpp)
  -> Interpreter          (interpreter.h / .cpp) -> PROGRAM OUTPUT
  -> Three Address Code  (tac.h / .cpp)
  -> Code Generation      (codegen.h / .cpp)
  -> Assembly Generation  (assembly.h / .cpp)
```

The **interpreter** is the only stage that produces the program's real output.
TAC / codegen / assembly exist purely for `--debug` mode and do not affect
execution.

---

## Table of Contents

1. [Project Structure](#project-structure)
2. [Architecture Overview](#architecture-overview)
3. [Supported Language Features](#supported-language-features)
4. [Prerequisites](#prerequisites)
5. [Running the Full Web App](#running-the-full-web-app)
6. [Building and Running Each Compiler](#building-and-running-each-compiler)
7. [Debug Mode](#debug-mode)
8. [What Each Module Does](#what-each-module-does)
9. [Grammar (CFG) Summary](#grammar-cfg-summary)
10. [Error Reporting](#error-reporting)
11. [References](#references)

---

## Project Structure

```
Temp_Compiler/
├── C_Compiler/          Mini C compiler (Flex + Bison + C++17)
│   ├── lexer.l              Lexical analyzer
│   ├── parser.y              Syntax analyzer + AST builder
│   ├── ast.h / ast.cpp       AST node definitions + debug printer
│   ├── symbol_table.h/.cpp   Variable table (name, type, scope, const, value)
│   ├── semantic.h/.cpp       Static checks
│   ├── interpreter.h/.cpp    Tree-walking interpreter -> real program output
│   ├── tac.h/.cpp            Three Address Code generator (debug only)
│   ├── codegen.h/.cpp        Pseudo target-machine instructions (debug only)
│   ├── assembly.h/.cpp       Pseudo x86 assembly (debug only)
│   ├── main.cpp              Driver / pipeline controller
│   ├── input.c                Sample test program
│   └── Makefile
│
├── CPP_Compiler/         Mini C++ compiler — same module layout as C_Compiler,
│                          C++-specific grammar/semantics (input.cpp)
│
├── Java_Compiler/        Mini Java compiler — same module layout,
│                          plus input.java
│
├── backend/               Node.js/Express/WebSocket backend
│   ├── server.js             Express static server + WebSocket upgrade
│   ├── socketHandler.js      Routes each WS session to a language runner
│   ├── runners/
│   │   ├── runC.js               Spawns C_Compiler/compiler.exe
│   │   ├── runCpp.js             Spawns CPP_Compiler/compiler.exe
│   │   ├── runJava.js            Spawns Java_Compiler/compiler.exe
│   │   └── runCompiler.js        Shared spawn/stdio/timeout logic
│   └── temp/                  Scratch dir for per-run source files
│
├── frontend/               Browser IDE (CodeMirror + xterm.js)
│   ├── index.html             Editor + terminal layout, language selector
│   ├── app.js                  WebSocket client, run/stop/input wiring
│   ├── style.css               Theme / layout
│   ├── xterm.js / xterm.css    Terminal emulator library
│   └── vendor/codemirror/       CodeMirror core + clike mode
│
└── project_report          Full technical write-up (design rationale,
                              CFGs, semantic rules, TAC examples, testing)
```

---

## Architecture Overview

All three compilers share the same design skeleton, differing only in
`lexer.l` / `parser.y` (language-specific grammar) and in the
language-specific parts of `semantic.cpp` / `interpreter.cpp`.

| Module | Input | Processing | Output | Next Consumer |
|---|---|---|---|---|
| `lexer.l` | Source characters | Pattern matching / tokenization | Token stream | `parser.y` |
| `parser.y` | Tokens | CFG recognition + AST-building actions | AST root | `semantic.cpp` / `tac.cpp` / `interpreter.cpp` |
| `ast.h`/`.cpp` | Parser-created nodes | One tagged `ASTNode` + `NodeType` enum, debug printer | AST structure | All AST walkers |
| `semantic.cpp` | AST | Declaration / control-flow / type checks | Error list or success | `main.cpp` |
| `symbol_table.cpp` | Declarations / lookups | Scope stack + symbol storage | Symbol entries | `semantic.cpp` / `interpreter.cpp` |
| `tac.cpp` | AST | Temporary/label lowering | TAC lines | Debug display |
| `interpreter.cpp` | AST + runtime symbol table | Tree-walking execution | Real program output | User / frontend |
| `main.cpp` | CLI input | Orchestrates all phases, stops on first error | Compiler / debug output | User / frontend |

**Design rationale**
- One tagged `ASTNode` class with a `NodeType` enum, instead of a class
  hierarchy per node kind — every phase switches on `node->type`.
- A scope stack in `SymbolTable`: a `main` (global-ish) scope plus a fresh
  scope pushed per `for` loop (and, in Java, per block).
- `break`/`continue` are implemented as small C++ exceptions
  (`BreakSignal`/`ContinueSignal`) that unwind to the nearest enclosing
  loop/switch, which naturally handles nested loops/switches.
- TAC / codegen / assembly are independent, purely educational AST walks
  used only in `--debug` mode.

---

## Supported Language Features

| Feature | C compiler | C++ compiler | Java compiler |
|---|---|---|---|
| int / integer literals | Yes | Yes | Yes |
| float, double | Yes | Yes | Yes |
| char | Yes | Yes | Yes |
| boolean type | No dedicated `bool` | Yes: `bool` | Yes: `boolean` |
| string type | String literals for printf/TAC only | Yes: `string` | Yes: `String` |
| const / final | `const` | `const` | `final` |
| Declaration with initializer | Yes | Yes | Yes |
| Multiple declarators per statement | Yes | Yes | No |
| Simple assignment | Yes | Yes | Yes |
| Compound assignment | `+= -= *= /= %=` | `+= -= *= /= %=` | `+= -= *= /= %=` |
| Increment/decrement | Prefix & postfix | Prefix & postfix | Prefix & postfix |
| Arithmetic | `+ - * / %` | `+ - * / %` (`+` also concatenates strings) | `+ - * / %` |
| Relational | `< > <= >= == !=` | `< > <= >= == !=` | `< > <= >= == !=` |
| Logical | `&& \|\| !` | `&& \|\| !` | `&& \|\| !` |
| Bitwise / shifts | `& \| ^ ~ << >>` | `& \| ^ ~ << >>` | `& \| ^ ~ << >>` |
| Ternary `?:` | Yes | Yes | Yes |
| if / else / else-if | Yes | Yes | Yes |
| while | Yes | Yes | Yes |
| do-while | Yes | Yes | Yes |
| for | Yes | Yes | Yes |
| switch / case / default | Yes | Yes | Yes |
| break / continue | Yes | Yes | Yes |
| return | Yes | Yes | Yes |
| Nested blocks | Parsed & traversed | Parsed & traversed | Parsed & traversed |
| C-style `printf` / `scanf` | Yes | No | No |
| C++ `cout` / `cin` / `endl` | No | Yes | No |
| Java `System.out.*` / `Scanner` | No | No | Yes |
| `sizeof` | Yes | Yes | No |
| Built-in math functions | `sqrt, pow, abs, ceil, floor` | No dedicated built-ins | No dedicated built-ins |
| Imports / includes | `#include` ignored | `#include` / `using namespace std;` ignored | `import` retained as AST no-op |
| Arrays / pointers / structs / classes | No | No | No user-defined classes |
| User-defined functions | No (main only) | No (main only) | No (main only) |
| Multi-declarator syntax | `int a, b = 2;` | One variable per statement | N/A |
| Program entry point | Single `int main() { ... }` | Single `int main() { ... }` | `public class ClassName { public static void main(String[] args) { ... } }` |

---

## Prerequisites

- **Flex** (lexer generator) — Windows: `win_flex` (from WinFlexBison)
- **Bison** (parser generator) — Windows: `win_bison` (from WinFlexBison)
- **g++** with **C++17** support (MinGW-w64 recommended on Windows)
- **Node.js** (v16+) and **npm**, for the web backend/frontend

---

## Running the Full Web App

The web app lets you pick C / C++ / Java from a dropdown, write code in a
CodeMirror editor, and run it in an embedded xterm.js terminal (including
interactive `stdin` via `cin` / `scanf` / `Scanner`).

**Prerequisite:** build `compiler.exe` in each of `C_Compiler/`,
`CPP_Compiler/`, and `Java_Compiler/` first (see below) —
`backend/runners/run*.js` spawn those exact binaries by path.

```powershell
cd backend
node server.js
```

Open **http://localhost:3000**. The Express/WebSocket backend serves the
frontend, spawns the matching `compiler.exe` for each run, and streams
its input/output to the browser's terminal in real time.

---

## Building and Running Each Compiler

All three compilers use the same build recipe from their own folder —
only the module list, input filename, and file extension change. Note that
`Java_Compiler`'s build line omits the `-Wall` flag used by `C_Compiler`
and `CPP_Compiler`.

```powershell
cd <C_Compiler | CPP_Compiler | Java_Compiler>

bison -d --defines=parser.tab.h -o parser.tab.cpp parser.y
flex -o lex.yy.cpp lexer.l

# C_Compiler / CPP_Compiler:
g++ -std=gnu++17 -Wall ast.cpp symbol_table.cpp semantic.cpp interpreter.cpp tac.cpp codegen.cpp assembly.cpp main.cpp lex.yy.cpp parser.tab.cpp -o compiler.exe

# Java_Compiler (no -Wall):
g++ -std=gnu++17 ast.cpp symbol_table.cpp semantic.cpp interpreter.cpp tac.cpp codegen.cpp assembly.cpp main.cpp lex.yy.cpp parser.tab.cpp -o compiler.exe

.\compiler.exe <input-file>            # prints only the program's own output
.\compiler.exe <input-file> --debug    # prints every compiler phase, then the output
.\compiler.exe                         # paste code directly into the terminal (finish with Ctrl+Z, Enter)
```

| Folder | Input file |
|---|---|
| `C_Compiler` | `input.c` |
| `CPP_Compiler` | `input.cpp` |
| `Java_Compiler` | `input.java` |

The Java compiler requires the standard boilerplate around `main`:

```java
public class ClassName {
    public static void main(String[] args) { ... }
}
```

---

## Debug Mode

Passing `--debug` after the input filename (or as the first arg with no
filename) prints every compiler phase in order before the actual program
output:

1. **Lexical Analysis** — every token the scanner produces, with its
   category (`KEYWORD`, `IDENTIFIER`, `INTEGER`, `FLOAT`, `CHAR`, `STRING`,
   `OP`, ...).
2. **Parser Output** — "Parsing Successful" or a detailed syntax error.
3. **AST Output** — the full indented tree via `printAST()`.
4. **Semantic Analysis** — "Semantic Analysis Successful" or the full list
   of semantic errors (with line numbers where available).
5. **Three Address Code (TAC)** — temporaries (`t1, t2, ...`) and labels
   (`L1, L2, ...`) for expressions and control flow.
6. **Code Generation** — a pseudo target-machine instruction view
   (`LOAD/STORE/ADD/CMP/JMP/...`) derived from the TAC.
7. **Assembly Output** — a pseudo x86 view (`MOV/ADD/SUB/CMP/JE/JMP/CALL/...`)
   derived from the TAC.
8. **Program Output** — the actual interpreter execution result (identical
   to non-debug mode's only output).
9. **Symbol Table (final values)** — every declared variable's final name,
   type, value, and scope after execution.

Without `--debug`, only section 8 (the real program output) is printed —
this is what the web frontend's terminal shows.

---

## What Each Module Does

- **`lexer.l`** — recognizes keywords, identifiers, numeric/char/string
  literals, operators, and comments, and skips preprocessor-style lines
  (`#include`, C++'s `using namespace std;`). Reports `Lexical Error` with
  a line number on an unrecognized character.
- **`parser.y`** — the Bison grammar; each semantic action directly builds
  `ASTNode*` objects, so the parser's output (`astRoot`) is immediately
  usable by every later phase. `yyerror()` reports detailed `Syntax Error`
  messages including the offending token.
- **`ast.h`/`ast.cpp`** — one tagged `ASTNode` class + `NodeType` enum;
  `printAST()` is the `--debug` tree dump.
- **`symbol_table.h`/`.cpp`** — a stack of scopes (`main`, plus a fresh
  scope per `for` loop) storing each variable's name, type, scope,
  const/final-ness, and current value.
- **`semantic.h`/`.cpp`** — walks the AST before anything runs, checking
  undeclared variables, duplicate declarations, literal division/modulo by
  zero, const/final violations, `break`/`continue` outside a loop or
  switch, and language-specific rules (C: bitwise ops need integer
  operands; C++: right-hand side of `cin >>` must be a plain variable;
  Java: `print()` requires an argument).
- **`interpreter.h`/`.cpp`** — the tree-walking interpreter; the only
  module that produces real program output. `break`/`continue` are C++
  exceptions unwound by the nearest loop/switch; `switch` fallthrough runs
  every case block in source order from the matched (or `default`) case
  until a `break` or the switch ends. Numeric values track a runtime
  `type` string (e.g. `int`, `long long`, `double`, `bool`) so arithmetic
  results and assignments follow the same type-promotion rules the
  language defines statically — e.g. the C++ interpreter widens integer
  binary-op results to the higher-ranked operand type
  (`unsigned long long > long long > long > int`), and mixed float/int
  operations promote to `float`/`double`.
- **`tac.h`/`.cpp`, `codegen.h`/`.cpp`, `assembly.h`/`.cpp`** — three
  independent AST walks producing progressively lower-level educational
  views (three-address code → pseudo target instructions → pseudo x86),
  used only for `--debug`. `break`/`continue` lower to `goto` the loop's
  start/end label here, exactly as a real compiler would.
- **`main.cpp`** — the driver: opens the input file (or reads pasted
  stdin), runs the lexer once for the token dump in debug mode, calls
  `yyparse()`, runs semantic analysis, optionally prints TAC/codegen/
  assembly, then runs the interpreter and (in debug mode) prints the
  final symbol table.

---

## Grammar (CFG) Summary

Each language has its own formal Context-Free Grammar implemented in
`parser.y`. The three grammars share a common statement/expression core
(`vardecl`, `assign_stmt`, `if/while/for`, `break/continue/return`,
arithmetic/relational/logical/bitwise expressions) and differ in:

- **C**: `printf`/`scanf` statements, `switch` with numeric/char case
  values, `sizeof`, built-in math function calls.
- **C++**: `cout`/`cin`/`endl` as ordinary binary-operator-compatible
  expressions, `bool`/`string` types, `switch` with arbitrary expression
  case values.
- **Java**: the outer `public class ... { public static void main(String[] args) { ... } }`
  wrapper, `import` declarations, `System.out.print/println`, and
  `new Scanner(...)`/`System.in`/`.nextInt()` etc. as postfix method calls.

Operator precedence (all three languages, lowest → highest):

| Level | Operators | Associativity |
|---|---|---|
| Lowest | `? :` | Right |
| | `\|\|` | Left |
| | `&&` | Left |
| | `\|` | Left |
| | `^` | Left |
| | `&` | Left |
| | `==, !=` | Left |
| | `<, >, <=, >=` | Non-associative |
| | `<<, >>` | Left |
| | `+, -` | Left |
| | `*, /, %` | Left |
| Highest | Unary operators (`- ! ~ ++ --`) | Non-associative |

Unary minus uses `%prec UMINUS`; the recursive `if/else/else-if` grammar
resolves the classic dangling-else ambiguity explicitly rather than
relying on Bison's default shift preference.

---

## Error Reporting

Errors are caught at the earliest possible phase and reported with a
category, a line number (where available), and a specific message:

```
Lexical Error:
Line 3: Unknown character '@'.

Syntax Error:
Line 5: syntax error, unexpected ')' (near token ')').

Semantic Error:
Line 3: Cannot modify constant variable 'x'

Runtime Error:
Division by zero.
```

- **Lexical errors** stop the C compiler immediately; the C++ compiler
  reports and continues scanning (configurable per lexer).
- **Syntax errors** stop compilation before any AST is used further.
- **Semantic errors** are collected into a list; if the list is non-empty,
  execution never starts and every collected error is printed.
- **Runtime errors** (e.g. division by zero not caught statically, invalid
  `scanf` input type) are thrown as C++ exceptions from the interpreter
  and caught in `main.cpp`, which prints the message and exits non-zero.

---

## References

[1] J. Smith, *From Source Code to Machine Code: Build Your Own Compiler
From Scratch*. build-your-own.org, May 18, 2023.
