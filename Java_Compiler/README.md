# Mini Java Compiler

A Flex + Bison + C++ compiler for a subset of Java, built the same way
as the Mini C and Mini C++ compilers before it — one Flex/Bison pair at
the core, one module per compiler phase.

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
MiniJavaCompiler/
├── lexer.l              Lexical analyzer (Flex)
├── parser.y              Syntax analyzer + AST builder (Bison)
├── ast.h / ast.cpp         AST node definitions + debug printer
├── symbol_table.h / .cpp    Variable table (name, type, scope, value)
├── semantic.h / .cpp         Static checks (undeclared vars, dup decls, div/0, invalid print, break/continue misuse)
├── interpreter.h / .cpp        Tree-walking interpreter -> real program output
├── tac.h / .cpp                  Three Address Code generator
├── codegen.h / .cpp                Pseudo target-machine instructions
├── assembly.h / .cpp                 Pseudo x86 assembly
├── main.cpp                            Driver / pipeline controller
├── input.java                           Sample test program
├── Makefile
└── README.md
```

## Supported Java subset

- Program shape: `public class Main { public static void main(String[] args) { ... } }`
  (the class name and the `args` parameter name are read but not otherwise
  used — any names are accepted there)
- Types: `int`, `float`, `double`, `char`, `boolean`, `String`
- Declarations & assignment: `int a = 5;`, `a = 10;`
- Compound assignment: `+= -= *= /=` (`+=` also works for `String`, as concatenation)
- Increment/decrement: `++a`, `a++`, `--a`, `a--`
- Arithmetic: `+ - * / %` (`+` also concatenates when either side is a `String`, exactly like real Java)
- Relational: `> < >= <= == !=`
- Logical: `&& || !`
- Control flow: `if`, `if / else`, `else if`, `while`, `for`, `break`, `continue`
- `System.out.print(...)` and `System.out.println(...)` (and `println()` with no argument)
- `return`
- No `import`/package statements needed in your test programs (the subset doesn't require them)

### Windows (win_flex / win_bison)

```
win_bison -d --defines=parser.tab.h -o parser.tab.cpp parser.y
win_flex -o lex.yy.cpp lexer.l
g++ -std=gnu++17 ast.cpp symbol_table.cpp semantic.cpp interpreter.cpp tac.cpp codegen.cpp assembly.cpp main.cpp lex.yy.cpp parser.tab.cpp -o compiler.exe
```

or simply:

```
make FLEX=win_flex BISON=win_bison
```

### Linux / macOS / MSYS2 (flex / bison)

```
make
```

which expands to:

```
bison -d --defines=parser.tab.h -o parser.tab.cpp parser.y
flex -o lex.yy.cpp lexer.l
g++ -std=gnu++17 ast.cpp symbol_table.cpp semantic.cpp interpreter.cpp tac.cpp codegen.cpp assembly.cpp main.cpp lex.yy.cpp parser.tab.cpp -o compiler.exe
```

### Run

```
.\compiler.exe input.java            # only the program's own output
.\compiler.exe input.java --debug    # every compiler phase, then the output
```

You can also paste code straight into the terminal instead of using a file:

```
.\compiler.exe
```
Paste your Java code, then press **Ctrl+Z, Enter** (Windows) — or
**Ctrl+D** (Linux/macOS) — on its own line to run it. `.\compiler.exe
--debug` does the same in debug mode.

(`make run` / `make debug` do the same using the bundled `input.java`.)

## What each module does

**lexer.l** — recognizes keywords, identifiers, numeric/char/string/
boolean literals, operators, comments, and the `System.out.print`/
`System.out.println` compound tokens.

**parser.y** — Bison grammar. Requires the `public class X { public
static void main(String[] args) { ... } }` shape, then builds an
`ASTNode*` tree for everything inside `main`; `astRoot` (declared in
`main.cpp`) ends up pointing at the finished tree.

**ast.h/.cpp** — one tagged `ASTNode` class (a `NodeType` enum says how
to read its fields) instead of one C++ class per node kind — every
other module switches on `node->type`. `printAST()` is the `--debug`
tree dump.

**symbol_table.h/.cpp** — a stack of scopes (`main`, plus a fresh scope
per `for` loop) storing each variable's name/type/scope/value
(including `String` values).

**semantic.h/.cpp** — walks the AST *before* anything runs, checking for
undeclared variables, duplicate declarations, literal division-by-zero,
`break`/`continue` used outside a loop, and invalid print usage
(`System.out.print()` with zero arguments — only `println()` may be
empty).

**interpreter.h/.cpp** — walks the AST and actually executes it: this is
the only module that produces the real program output. `break`/
`continue` are implemented as C++ exceptions that unwind out of the
nearest loop's body (a `for` loop still runs its update step after a
`continue`, exactly like real Java).

**tac.h/.cpp / codegen.h/.cpp / assembly.h/.cpp** — three more (separate)
walks over the AST that print, purely for `--debug`, three progressively
lower-level educational views of the same program: three-address code,
pseudo target instructions, and pseudo x86 assembly. `break`/`continue`
become `goto` to the loop's start/end label, and `System.out.print`/
`println` become `PRINT`/`PRINT_NEWLINE` pseudo-instructions (or
`CALL System.out.print` / `CALL System.out.println_newline` in the
assembly view), exactly as a real compiler would lower them. These views
do not affect execution — the interpreter is what actually runs the code.

