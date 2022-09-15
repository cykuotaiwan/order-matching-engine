CC = g++
CFLGA = -Wall -g
STD = --std=c++17
EXE = matching-engine

BINDIR = bin/
BLDDIR = build/
TESTDIR = test/
SRCDIR = src/

all: main

main: $(SRCDIR)main.cpp
	$(CC) $(CFLGA) $(STD) -o $(BINDIR)$(EXE) $(SRCDIR)main.cpp


.PHONY: all clean
clean:
	rm $(BLDDIR)*O