CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

code: test.cpp Role.hpp
	$(CXX) $(CXXFLAGS) test.cpp -o code

clean:
	rm -f code
