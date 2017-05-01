/**
 * Replacement algorithm base class implementation
 */
#include "Replacer.h"
#include "PageTable.h"
using namespace std;

Replacer::Replacer(PageTable* pageTable) {
	this->pageTable = pageTable;
	numPageFaults = 0;
}

void Replacer::replaceVictimPageWith(Page* newPage) {
	Page* victimPage = getVictimPage();
	victimPage->valid = false;
	newPage->frame = victimPage->frame;
	numPageFaults += 1;
}
