/**
 * Replacement algorithm base class implementation
 */
#include "Replacer.h"
#include "PageTable.h"
#include "FrameList.h"
using namespace std;

Replacer::Replacer(PageTable* pageTable, FrameList* freeFrames) {
	this->pageTable = pageTable;
}
