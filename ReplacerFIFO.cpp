/**
 * FIFO page replacement algorithm implementation
 */
#include "Page.h"
#include "PageTable.h"
#include "ReplacerFIFO.h"
#include <iostream>

using namespace std;


ReplacerFIFO::ReplacerFIFO(PageTable* pageTable, int numFrames) : Replacer(pageTable, numFrames) {
	// Constructor doesn't need to do anything currently
}

Page* ReplacerFIFO::getVictimPage() {
	Page* victimPage = pageQueue.front();
	pageQueue.pop();
	return victimPage;
}

void ReplacerFIFO::processPage(Page* page) {
	if (!page->valid) {
		if (numFreeFrames == 0) {
			replaceVictimPageWith(page);
		} else {
			page->frame = numFrames - numFreeFrames;
			numFreeFrames -= 1;
			numPageFaults++;
		}
		pageQueue.push(page);
		page->valid = true;
	}
}
