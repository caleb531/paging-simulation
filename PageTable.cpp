/**
 * Page table implementation
 */
#include "PageTable.h"
#include <iostream>
using namespace std;

PageTable::PageTable(int numPages, int numFrames) {
	pages = new Page[numPages];
	this->numPages = numPages;
	this->numFrames = numFrames;
	this->numFreeFrames = numFrames;
}
