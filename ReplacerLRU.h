/**
 * LRU page replacement algorithm definition
 */
#pragma once
#include <queue>
#include <vector>
#include "PageTable.h"
#include "Replacer.h"
using namespace std;

class ReplacerLRU : public Replacer {

	protected:

		priority_queue<Page*, vector<Page*>, PageComparator> pageQueue;
		
	public:

		ReplacerLRU(PageTable* pageTable, int numFrames);
		virtual Page* getVictimPage();
		virtual void processPage(Page* page);

};
