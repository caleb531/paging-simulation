/**
 * Page definition
 */
#pragma once
using namespace std;

class Page {

	public:

		// The frame to which this page is pointing; a value of -1 indicates
		// that the page is
		int frame;
		// A flag indicating if the page is dirty
		bool dirty;
		// A flag indicating if the page is valid
		bool valid;
		// The time the page was last accessed (used for LRU)
		int lastAccessTime;

		// Constructor
		Page();

};
