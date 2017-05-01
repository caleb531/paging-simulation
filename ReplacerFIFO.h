/**
 * FIFO page replacement algorithm definition
 */
#pragma once
#include <queue>
#include "PageTable.h"
#include "Replacer.h"
using namespace std;

class ReplacerFIFO : public Replacer {

	protected:

		queue<Page*> pageQueue;

	public:

		ReplacerFIFO(PageTable* pageTable);
		virtual Page* getVictimPage();
		virtual void process(Page* page);

};
