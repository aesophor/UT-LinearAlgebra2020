CXX=g++
CXXFLAGS=-g -flto -Os -Wall
SRC=$(wildcard src/*.cc)
BIN=main

all:
	$(CXX) -o $(BIN) $(SRC) $(CXXFLAGS)

clean:
	rm $(BIN)

run:
	./main
