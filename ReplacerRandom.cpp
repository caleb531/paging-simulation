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
	int victimPageIndex = randomizer() % validPages.size();
	victimPage = &(pageTable->pages[victimPageIndex]);
	return victimPage;
}


void ReplacerRandom::processPage(Page* page) {
	if (!page->valid) {
		if (numFreeFrames == 0) {
			Page* victimPage = replaceVictimPageWith(page);
			// Efficiently remove victim page from valid page list
			swap(validPages[victimPage->pageNum], validPages[page->pageNum]);
			validPages.pop_back();
		} else {
			page->frame = numFrames - numFreeFrames;
			numFreeFrames -= 1;
			//numPageFaults++;
		}
		page->valid = true;
		validPages.push_back(page->pageNum);
	}
}
