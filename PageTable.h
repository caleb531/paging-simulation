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

		// Constructor
		PageTable(int numPages);

};
