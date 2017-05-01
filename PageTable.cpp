/**
 * Page table implementation
 */
#include "PageTable.h"
#include <iostream>
using namespace std;

PageTable::PageTable(int numPages) {
	pages = new Page[numPages];
}
