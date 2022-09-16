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

test: testOrderBook

testOrderBook: $(TESTDIR)testOrderBook.cpp
	$(CC) $(CFLGA) $(STD) -o $(BINDIR)testOrderBook $(TESTDIR)testOrderBook.cpp $(SRCDIR)order/order.cpp $(SRCDIR)order/orderBook.cpp $(SRCDIR)order/orderKey.cpp


.PHONY: all clean
clean:
	rm $(BLDDIR)*O