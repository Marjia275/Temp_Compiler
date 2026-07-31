# ============================================================
# Makefile - Mini C Compiler
#
# On Windows (with win_flex / win_bison installed and on PATH):
#   make FLEX=win_flex BISON=win_bison
#
# On Linux / macOS (with flex / bison installed):
#   make
# ============================================================

FLEX   ?= flex
BISON  ?= bison
CXX    ?= g++
CXXFLAGS ?= -std=c++17 -Wall

TARGET = compiler.exe

SOURCES = ast.cpp symbol_table.cpp semantic.cpp interpreter.cpp \
          tac.cpp codegen.cpp assembly.cpp main.cpp \
          lex.yy.cpp parser.tab.cpp

.PHONY: all clean run debug

all: $(TARGET)

# IMPORTANT: we generate lex.yy.cpp / parser.tab.cpp (NOT .c) so that
# g++ compiles them as C++ - required because our %union stores
# std::string* and ASTNode* pointers, which plain C cannot express.

parser.tab.cpp parser.tab.h: parser.y
	$(BISON) -d --defines=parser.tab.h -o parser.tab.cpp parser.y

lex.yy.cpp: lexer.l parser.tab.h
	$(FLEX) -o lex.yy.cpp lexer.l

$(TARGET): parser.tab.cpp lex.yy.cpp $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET) input.c

debug: $(TARGET)
	./$(TARGET) input.c --debug

clean:
	rm -f $(TARGET) lex.yy.cpp parser.tab.cpp parser.tab.h
