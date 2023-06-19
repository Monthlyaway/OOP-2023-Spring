#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Interval {
public:
	Interval(int s, int e) : start(s), end(e) {}
	int start, end;
};

typedef vector<Interval> Intervals;

bool compare_interval(const Interval& a, const Interval& b) {
	return a.start < b.start;
}

Intervals merge_intervals(Intervals& intervals) {
	Intervals merged;
	if (intervals.empty())
		return merged;
	sort(intervals.begin(), intervals.end(), compare_interval);

	for (std::size_t idx = 0; idx < intervals.size(); ++idx) {
		const Interval& interval = intervals[idx];
		if (!merged.empty() && interval.start < merged.back().end)
			merged.back().end = std::max(interval.end, merged.back().end);
		else
			merged.push_back(interval);
	}
	return merged;
}

int main() {
	Intervals vec = {
   Interval(15, 18), Interval(2, 6),
   Interval(5, 10), Interval(1, 3)
	};
	Intervals merged = merge_intervals(vec);

	for (std::size_t idx = 0; idx < merged.size(); ++idx) {
		const Interval& interval = merged.at(idx);
		std::cout << "[" << interval.start << "," << interval.end << "]" << ",";
	};


	return 0;
}