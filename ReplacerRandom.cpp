/**
 * Random page replacement algorithm implementation
 */
#include <cstdlib>
#include <iostream>
#include "Page.h"
#include "PageTable.h"
#include "ReplacerRandom.h"
using namespace std;


ReplacerRandom::ReplacerRandom(PageTable* pageTable, int numFrames) : Replacer(pageTable, numFrames) {
	srand(time(NULL));
}

Page* ReplacerRandom::getVictimPage() {
	Page* victimPage;
	int victimPageIndex = rand() % validPages.size();
	victimPage = pageTable->pages[victimPageIndex];
	// Efficiently remove victim page from valid page list
	swap(validPages[victimPageIndex], validPages[validPages.size() - 1]);
	validPages.pop_back();
	return victimPage;
}


void ReplacerRandom::processPage(Page* page) {
	if (!page->valid) {
		if (numFreeFrames == 0) {
			Page* victimPage = replaceVictimPageWith(page);
		} else {
			page->frame = numFrames - numFreeFrames;
			numFreeFrames -= 1;
			numPageFaults++;
		}
		page->valid = true;
		validPages.push_back(page->pageNum);
	}
}
