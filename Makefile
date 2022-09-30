CC = g++
CFLGA = -Wall -g
STD = --std=c++17
EXE = matching-engine

BINDIR = bin/
BLDDIR = build/
TESTDIR = test/
SRCDIR = src/
UTILDIR = src/util/

all: main

main: $(SRCDIR)main.cpp
	$(CC) $(CFLGA) $(STD) -o $(BINDIR)$(EXE) $(SRCDIR)main.cpp

test: testOrderBook testOrder testOrderKey

testOrderBook: $(TESTDIR)testOrderBook.cpp
	$(CC) $(CFLGA) $(STD) -o $(BINDIR)testOrderBook $(TESTDIR)testOrderBook.cpp $(SRCDIR)order/order.cpp $(SRCDIR)order/orderBook.cpp $(SRCDIR)order/orderKey.cpp

testOrder: $(TESTDIR)testOrder.cpp
	$(CC) $(CFLGA) $(STD) -o $(BINDIR)testOrder $(TESTDIR)testOrder.cpp $(SRCDIR)order/order.cpp $(SRCDIR)order/orderKey.cpp

testOrderKey: $(TESTDIR)testOrderKey.cpp
	$(CC) $(CFLGA) $(STD) -o $(BINDIR)testOrderKey $(TESTDIR)testOrderKey.cpp $(SRCDIR)order/orderKey.cpp $(UTILDIR)testUtil.cpp


.PHONY: all clean
clean:
	rm $(BLDDIR)*O