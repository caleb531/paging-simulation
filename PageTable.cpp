/**
 * Page table implementation
 */
#include "PageTable.h"
#include <iostream>
using namespace std;

PageTable::PageTable(int numPages) {
	this->numPages = numPages;
	pages = new Page[numPages];
	// Store the page number with each page (for convenience)
	for (int i = 0; i < numPages; i++) {
		pages[i].pageNum = i;
	}
}
