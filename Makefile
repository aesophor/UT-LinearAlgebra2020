CXX=g++
CXXFLAGS=-g -std=c++11 -flto -Os -Wall
SRC=$(wildcard src/*.cc)
BIN=gauss_jordan_elimination_test

all:
	$(CXX) -o $(BIN) $(SRC) $(CXXFLAGS)

clean:
	rm $(BIN)

run:
	./main
