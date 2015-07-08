#include <iostream>
#include <algorithm>
#include <vector>

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

std::vector<timeTuple> mergeRanges(std::vector<timeTuple> ranges) {
	// Start by sorting the timeTuples
	std::sort(ranges.begin(), ranges.end(), timeTupleComp);

	auto front = ranges.begin();
	auto prev = ranges.begin();
	for (auto curr = ranges.begin() + 1; curr != ranges.end(); curr++) {
		if (prev->endTime > curr->startTime) {
			// merge prev with curr
			curr->startTime = prev->startTime;
			front = curr;
		}
	}

	return std::vector<timeTuple>(front, ranges.end());
}


int main() {

	std::vector<timeTuple> ranges;
	ranges.emplace_back(0,1);
	ranges.emplace_back(3,5);
	ranges.emplace_back(4,8);
	ranges.emplace_back(10,12);
	ranges.emplace_back(9,10);

	return 0;
}
