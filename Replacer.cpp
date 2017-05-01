/**
 * Replacement algorithm base class implementation
 */
#include "Replacer.h"
#include "PageTable.h"
using namespace std;

Replacer::Replacer(PageTable* pageTable) {
	this->pageTable = pageTable;
}
