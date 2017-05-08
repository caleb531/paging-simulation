#!/usr/bin/make

CXX = g++
CXXFLAGS = -std=c++11
SRC = *.cpp
PROG = sim.out

# Clean project and compile program
build: clean $(PROG)

# Clean project by removing existing executable file
clean:
	rm -f $(PROG)

# Compile the program from the latest source
$(PROG): $(SRC)
	$(CXX) $(SRC) $(CXXFLAGS) -o $(PROG)
