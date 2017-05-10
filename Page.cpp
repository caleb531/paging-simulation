/**
 * Page implementation
 */
#include "Page.h"
#include <sys/time.h>
using namespace std;

Page::Page() {
	pageNum = -1;
	frame = -1;
	lastAccessTime = 0;
	dirty = false;
	valid = false;
}

void Page::updateLastAccessTime() {
	timeval timePtr;
	gettimeofday(&timePtr, NULL);
	lastAccessTime = timePtr.tv_sec + (timePtr.tv_usec / 1000000.0);
}

bool PageComparator::operator ()(Page* a, Page* b) {
	return a->lastAccessTime > b->lastAccessTime;
}
