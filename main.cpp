/**
 * CS 433 Programming Assignment 5: Memory Paging Simulation
 * Caleb Evans, Jonathan Tapia
 */
#include <iostream>
#include <cstdlib>
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

int main(int argc, char* argv[]) {
	int pageSize, physicalMemorySize;

	printProgramHeader();

	if (argc != 3) {
		cout << "Usage: " << argv[0] << " Page_Size Physical_Memory_Size"<< endl;
		return 1;
	}

	// Note: atoi() doens't check for valid input
	pageSize = atoi(argv[1]);
	physicalMemorySize = atoi(argv[2]);

	if (pageSize < 256 || pageSize > 8192) {
		cout << "Page_Size must be between 256 and 8192 inclusive" << endl;
		return 1;
	}
	else if (!isPowerOfTwo(pageSize) || !isPowerOfTwo(physicalMemorySize)) {
		cout << "Page_Size and Physical_Memory_Size must be powers of 2" << endl;
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
