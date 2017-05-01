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

		// The number of page faults generated while running the replacement
		// algorithm
		int numPageFaults = 0;

		Replacer(PageTable* pageTable);
		// Replace the victim page with a new page
		virtual Page* getVictimPage() = 0;
		// Replace the victim page with a new page
		void replaceVictimPageWith(Page* newPage);
		// Process the given page, running the replacement algorithm as needed
		virtual void process(Page* page) = 0;

};
