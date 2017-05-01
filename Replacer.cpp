/**
 * Replacement algorithm base class implementation
 */
#include "Replacer.h"
#include "PageTable.h"
using namespace std;

Replacer::Replacer(PageTable* pageTable, int numFrames) {
	this->pageTable = pageTable;
	this->numFrames = numFrames;
	this->numFreeFrames = numFrames;
	numPageFaults = 0;
}

Page* Replacer::replaceVictimPageWith(Page* newPage) {
	Page* victimPage = getVictimPage();
	victimPage->valid = false;
	newPage->frame = victimPage->frame;
	numPageFaults += 1;
	return victimPage;
}
