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

		Replacer(PageTable* pageTable);
		// Process the given page, running the replacement algorithm as needed
		virtual void process(Page* page) = 0;

};
