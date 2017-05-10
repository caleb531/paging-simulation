/**
 * FIFO page replacement algorithm implementation
 */
#include "Page.h"
#include "PageTable.h"
#include "ReplacerLRU.h"
#include <iostream>
#include <sys/time.h>

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

	timeval timePtr;
	gettimeofday(&timePtr, NULL);

	page->lastAccessTime = timePtr.tv_sec + (timePtr.tv_usec / 1000000.0);

}
