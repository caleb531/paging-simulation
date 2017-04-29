/**
 * Page table implementation
 */
#include "PageTable.h"
#include <iostream>
using namespace std;

PageTable::PageTable(int numPages) {
	pages = new Page*[numPages];
	for (int i = 0; i < numPages; i++) {
		pages[i] = new Page;
	}
}
