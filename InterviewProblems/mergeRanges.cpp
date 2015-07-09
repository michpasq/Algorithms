#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

// NOTES:
// "Moral" noted above mergeRanges()
// mergeRanges() works in place! Of course it is pass by value, though, which makes a copy.

struct timeTuple {
	int startTime;
	int endTime;
	timeTuple(int a, int b) : startTime(a), endTime(b) {};
};

bool timeTupleComp(const timeTuple& a, const timeTuple& b) {
	if (a.startTime == b.startTime) {
		return a.endTime < b.endTime;
	}
	else {
		return a.startTime < b.startTime;
	}
};


// Moral to take away: 
// When merging in one loop (and sorted order), move "curr" iterator always,
// but modify only "prev" iterator to merge the time ranges...
std::vector<timeTuple> mergeRanges(std::vector<timeTuple> ranges) {
	// Start by sorting the timeTuples
	std::sort(ranges.begin(), ranges.end(), timeTupleComp);

	auto prev = ranges.begin();
	for (auto curr = ranges.begin() + 1; curr != ranges.end(); curr++) {
		if (prev->endTime >= curr->startTime) {
			// merge prev with curr
			prev->endTime = std::max(prev->endTime, curr->endTime);
		}
		else {
			prev++;
			prev->startTime = curr->startTime;
			prev->endTime = curr->endTime;
		}
		
	}

	return std::vector<timeTuple>(ranges.begin(), prev + 1);
}


int main() {

	std::vector<timeTuple> ranges;
	// ranges.emplace_back(0,1);
	// ranges.emplace_back(3,5);
	// ranges.emplace_back(4,8);
	// ranges.emplace_back(10,12);
	// ranges.emplace_back(9,10);

	// ranges.emplace_back(1,3);
	// ranges.emplace_back(2,4);

	ranges.emplace_back(1,10);
	ranges.emplace_back(2,6);
	ranges.emplace_back(3,5);
	ranges.emplace_back(7,9);
	
	std::vector<timeTuple> mergedRanges = mergeRanges(ranges);

	for (auto& i : mergedRanges) {
		printf("(%i, %i)\n", i.startTime, i.endTime);
	}

	return 0;
}
