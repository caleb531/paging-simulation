/**
 * FIFO page replacement algorithm implementation
 */
#include "Page.h"
#include "PageTable.h"
#include "ReplacerLRU.h"
#include <iostream>

using namespace std;


ReplacerLRU::ReplacerLRU(PageTable* pageTable, int numFrames) : Replacer(pageTable, numFrames) {
	// Constructor doesn't need to do anything currently
}

Page* ReplacerLRU::getVictimPage() {
	Page* victimPage = pageQueue.top();
	pageQueue.pop();
	return victimPage;
}

void ReplacerLRU::processPage(Page* page) {

	page->updateLastAccessTime();
	if (!page->valid) {
		if (numFreeFrames == 0) {
			replaceVictimPageWith(page);
		} else {
			page->frame = numFrames - numFreeFrames;
			numFreeFrames -= 1;
		}
		page->valid = true;
	}
	pageQueue.push(page);

}
