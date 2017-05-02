/**
 * Replacement algorithm base class definition
 */
#pragma once
#include "PageTable.h"
using namespace std;

class Replacer {

	protected:

		PageTable* pageTable;

	public:

		// The total number of frames in physical memory
		int numFrames;
		// The total number of available frames
		int numFreeFrames;
		// The number of page faults generated while running the replacement
		// algorithm
		int numPageFaults;

		Replacer(PageTable* pageTable, int numFrames);
		// Replace the victim page with a new page
		virtual Page* getVictimPage() = 0;
		// Replace the victim page with a new page
		Page* replaceVictimPageWith(Page* newPage);
		// Process the given page, running the replacement algorithm as needed
		virtual void processPage(Page* page) = 0;

};
