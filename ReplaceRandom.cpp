/**
 * Random page replacement algorithm implementation
 */
#include <iostream>
#include "Page.h"
#include "PageTable.h"
#include "ReplacerRandom.h"
using namespace std;


ReplacerRandom::ReplacerRandom(PageTable* pageTable, int numFrames) : Replacer(pageTable, numFrames) {
	// Constructor doesn't need to do anything currently
}

Page* ReplacerRandom::getVictimPage() {
	Page* victimPage;
	// See <http://stackoverflow.com/a/3052796/560642> for how to select a
	// random element from a set
	set<int>::const_iterator pageIterator(validPages.begin());
	advance(pageIterator, rand() % validPages.size());
	int victimPageIndex = *pageIterator;
	victimPage = &pageTable->pages[victimPageIndex];
	return victimPage;
}


void ReplacerRandom::processPage(Page* page) {
	if (!page->valid) {
		if (numFreeFrames == 0) {
			Page* victimPage = replaceVictimPageWith(page);
			validPages.erase(victimPage->pageNum);
		} else {
			page->frame = numFrames - numFreeFrames;
			numFreeFrames -= 1;
		}
		page->valid = true;
		validPages.insert(page->pageNum);
	}
}
