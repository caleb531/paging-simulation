/**
 * Random page replacement algorithm definition
 */
#pragma once
#include <vector>
#include "PageTable.h"
#include "Replacer.h"
using namespace std;

class ReplacerRandom : public Replacer {

	protected:

		// Keep a list of the page numbers of the currently-valid pages (to
		// choose from randomly later)
		vector<int> validPages;

	public:

		ReplacerRandom(PageTable* pageTable, int numFrames);
		virtual Page* getVictimPage();
		virtual void processPage(Page* page);

};
