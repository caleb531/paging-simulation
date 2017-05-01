/**
 * Unordered frame list definition
 */
#pragma once
#include <set>
using namespace std;

// An unordered list of frames, where each frame is represented as an integer
// (i.e. simpliy the frame number)
class FrameList {

	protected:

		// The list is internally implemented as a set for O(1) lookup times,
		// particularly since order does not matter
		set<int> frames;

	public:

		// The current number of frames in the list
		int count;

		// Constructor
		FrameList();
		// Add a frame to the list
		void add(int frame);
		// Remove a frame from the list, silently failing if the frame doesn't
		// exist
		void remove(int frame);
		// Return true if the given frame is in the list; otherwise, return false
		bool contains(int frame);
		// Return true if the list is empty; otherwise, return false
		bool isEmpty();

};
