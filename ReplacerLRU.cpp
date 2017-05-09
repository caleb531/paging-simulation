/**
 * FIFO page replacement algorithm implementation
 */
#include "Page.h"
#include "PageTable.h"
#include "ReplacerLRU.h"
#include <iostream>
#include <ctime>

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
	if (!page->valid) {
		if (numFreeFrames == 0) {
			replaceVictimPageWith(page);
		} else {
			page->frame = numFrames - numFreeFrames;
			numFreeFrames -= 1;
		}
		pageQueue.push(page);
		page->valid = true;
	}

	page->lastAccessTime = time(NULL);
}