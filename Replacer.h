/**
 * Replacement algorithm base class definition
 */
#pragma once
#include "FrameList.h"
#include "PageTable.h"
using namespace std;

class Replacer {

	protected:

		PageTable* pageTable;

	public:

		Replacer(PageTable* pageTable, FrameList* freeFrames);
		// Process the given page, running the replacement algorithm as needed
		virtual void process(Page* page) = 0;

};
