#include "Algorithm.h"

#include <iostream>
#include <ranges>
#include <numeric>
#include <algorithm>



double Algorithm::Mean(const vector<int>& data) {
	int sum = accumulate(data.begin(), data.end(), 0);
	return static_cast<double>(sum) / static_cast<double>(data.size());
}

double Algorithm::StdDev(const vector<int>& data) {
	auto mean = Mean(data);

	double dev = accumulate(data.begin(), data.end(), 0.0);

	return std::sqrt(dev / (data.size() - 1));
}

int Algorithm::Median(vector<int> data) {
	if (data.size() == 0) return 0;

	std::sort(data.begin(), data.end());

	size_t medianPoint = data.size() / 2;

	if (medianPoint % 2 == 1) {
		return data[medianPoint];
	}
	else {
		return (data[medianPoint - 1] + data[medianPoint]) / 2;
	}
}