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
		// Process the given page number and write flag
		virtual void process(int pageNum, Page* page) = 0;

};
