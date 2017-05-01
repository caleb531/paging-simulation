/**
 * CS 433 Programming Assignment 5: Memory Paging Simulation
 * Caleb Evans, Jonathan Tapia
 */
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include "PageTable.h"
#include "ReplacerFIFO.h"
using namespace std;

// Constants used for byte conversions
static const int B_TO_KB = 1024;
static const int KB_TO_MB = 1024;
// The size of the logical memory (in bytes)
static const int logicalMemorySize = 128 * B_TO_KB * KB_TO_MB;

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

// Get the page number for the given memory reference / binary address
int getPageNum(int memRef) {
	return memRef >> 12;
}

// Return true if the given byte address has write access; otherwise, return
// false
bool hasWriteAccess(int memRef) {
	return memRef % 2 == 1;
}


int main(int argc, char* argv[]) {

	printProgramHeader();

	int pageSize = getIntArg(argv[1], "page size");
	int physicalMemorySize = getIntArg(argv[2], "physical memory size");

	if (pageSize < 256 || pageSize > 8192) {
		cout << "Page size must be between 256 and 8192 inclusive" << endl;
		return 1;
	}
	else if (!isPowerOfTwo(pageSize)) {
		cout << "Page size must be power of 2" << endl;
		return 1;
	}
	else if (!isPowerOfTwo(physicalMemorySize)) {
		cout << "Physical memory size must be power of 2" << endl;
		return 1;
	}

	cout << "Page size: " << pageSize << " B" << endl;
	cout << "Physical memory size: " << physicalMemorySize << " MB" << endl;
	// Physical memory size is given in MB, but must be converted to B
	physicalMemorySize *= B_TO_KB * KB_TO_MB;

	ifstream refFile("references.txt");

	int numPages = logicalMemorySize / pageSize;
	cout << "# Pages: " << numPages << endl;

	PageTable* pageTable = new PageTable(numPages);

	Replacer* replacer = new ReplacerFIFO(pageTable);

	int memRef;
	while (refFile >> memRef) {

		int pageNum = getPageNum(memRef);
		bool canWrite = hasWriteAccess(memRef);
		Page page = pageTable->pages[pageNum];

		// // Currently, this triggers a segfault if pageNum >= numPages, which
		// is usually the case (e.g. run program with "8192 16" as arguments)
		if (hasWriteAccess) {
			page.dirty = true;
		}

		replacer->process(pageNum, &page);

	}

	// Do stuff here

	/*Stuff to do:
		Determine how to choose between algorithms and how to track data
		How pagetable entries should be handled (classes, int, ?)
		How freeframe list should be handeld
	*/

	delete pageTable;
	delete replacer;

	refFile.close();
	return 0;
}
