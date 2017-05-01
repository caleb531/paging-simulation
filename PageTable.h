/**
 * Page table definition
 */
#pragma once
#include <set>
#include "Page.h"
using namespace std;

class PageTable {

	public:

		// The table of page data
		Page* pages;

		// The total number of pages in logical memory
		int numPages;
		// The total number of frames in physical memory
		int numFrames;
		// The total number of available frames
		int numFreeFrames;

		// Constructor
		PageTable(int numPages, int numFrames);

};
