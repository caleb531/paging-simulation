/**
 * FIFO page replacement algorithm implementation
 */
#include "Page.h"
#include "PageTable.h"
#include "ReplacerFIFO.h"
#include <iostream>

using namespace std;


ReplacerFIFO::ReplacerFIFO(PageTable* pageTable) : Replacer(pageTable) {
	// Constructor doesn't need to do anything currently
}

void ReplacerFIFO::process(Page* page) {

	if (!page->valid) {
		if (!pageQueue.empty()) {
			pageQueue.pop();
		}
		pageQueue.push(page);
		page->valid = true;
	}

}
