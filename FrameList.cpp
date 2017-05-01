/**
 * Unordered frame list implementation
 */
#include "FrameList.h"
using namespace std;


FrameList::FrameList() {
	count = 0;
}

void FrameList::add(int frame) {
	frames.insert(frame);
	count += 1;
}

void FrameList::remove(int frame) {
	frames.erase(frame);
	count -= 1;
}

bool FrameList::contains(int frame) {
	return (frames.find(frame) != frames.end());
}

bool FrameList::isEmpty() {
	return (count == 0);
}
