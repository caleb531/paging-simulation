/**
 * Page definition
 */
#pragma once
using namespace std;

class Page {

	public:

		// The page number (i.e. the index in the page table where the page can
		// be found); a value of -1 indicates the page has not been fully
		// instantiated yet
		int pageNum;
		// The frame to which this page is pointing; a value of -1 indicates
		// that the page is not pointing to any frame
		int frame;
		// A flag indicating if the page is dirty
		bool dirty;
		// A flag indicating if the page is valid
		bool valid;
		// The time the page was last accessed (used for LRU)
		double lastAccessTime;

		// Constructor
		Page();
		// Update the last access time of the page to the current time
		void updateLastAccessTime();

};

// Define a custom comparator so Page pointers can be used in priority queues
class PageComparator {
	public:
		bool operator()(Page* a, Page* b);
};
