#include <iostream>
#include <algorithm>
#include <vector>

struct timeTuple {
	int startTime;
	int endTime;
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

	for (auto it = begin(ranges); it != end(ranges); it++) {
		true;
	}
}


int main() {

	return 0;
}
