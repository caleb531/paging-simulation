/**
 * Page implementation
 */
#include "Page.h"
using namespace std;

Page::Page() {
	pageNum = -1;
	frame = -1;
	lastAccessTime = 0;
	dirty = false;
	valid = false;
}
