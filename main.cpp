/**
 * CS 433 Programming Assignment 5: Memory Paging Simulation
 * Caleb Evans, Jonathan Tapia
 */
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
using namespace std;

// Print the basic program information
void printProgramHeader() {
	cout << "CS 433 Paging Simulation" << endl;
	cout << "Authors: Caleb Evans, Jonathan Tapia" << endl;
	cout << endl;
}

bool isPowerOfTwo(int n) {
	if (n == 0){
		return false;
	}

	return ((n & (n - 1)) == 0);
}

// Return the given string argument as an integer
int getIntArg(char* strArg, const char* argLabel) {
	if (!strArg) {
		cerr << "Missing argument for " << argLabel << endl;
		exit(1);
	}
	// Read string argument into stream and then read stream into integer to
	// perform conversion
	istringstream stream(strArg);
	int intArg;
	if (stream >> intArg) {
		return intArg;
	} else {
		cerr << "Invalid " << argLabel << ": " << strArg << endl;
		exit(1);
	}
}

int main(int argc, char* argv[]) {
	int pageSize, physicalMemorySize;

	printProgramHeader();

	pageSize = getIntArg(argv[1], "page size");
	physicalMemorySize = getIntArg(argv[2], "physical memory size");

	if (pageSize < 256 || pageSize > 8192) {
		cout << "Page size must be between 256 and 8192 inclusive" << endl;
		return 1;
	}
	else if (!isPowerOfTwo(pageSize) || !isPowerOfTwo(physicalMemorySize)) {
		cout << "Page size and physical memory size must be powers of 2" << endl;
		return 1;
	}


	ifstream input;
	input.open("references.txt");

	int numPages = physicalMemorySize / pageSize;
	int pageTable[numPages];

	// Do stuff here

	/*Stuff to do:
		Determine how to choose between algorithms and how to track data
		How pagetable entries should be handled (classes, int, ?)
		How freeframe list should be handeld
	*/

	input.close();
	return 0;
}
