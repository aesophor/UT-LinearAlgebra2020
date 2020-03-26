CXX=g++
CXXFLAGS=-g -std=c++11 -flto -Os -Wall -I.

%: %.cc
	$(CXX) -o $@ $< $(CXXFLAGS)

test:
	make tests/fraction_arithmetic_test
	make tests/gauss_jordan_elimination_test

clean:
	rm tests/*_test

install:
	mkdir -p /usr/local/include/matricks
	install -D -m755 matricks/* /usr/local/include/matricks

uninstall:
	rm -rf /usr/local/include/matricks
