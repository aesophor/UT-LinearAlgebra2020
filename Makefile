CXX=g++
CXXFLAGS=-g -std=c++11 -flto -Os -Wall -I.

%: %.cc
	$(CXX) -o $@ $< $(CXXFLAGS)

test:
	make tests/gauss_jordan_elimination_test

clean:
	rm tests/*_test

run:
	./main
