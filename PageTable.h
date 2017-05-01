/**
 * Page table definition
 */
#pragma once
#include <set>
#include "Page.h"
using namespace std;

class PageTable {

	public:

		// The table of page data
		Page* pages;

		// The total number of pages in logical memory
		int numPages;

		// Constructor
		PageTable(int numPages);

};
