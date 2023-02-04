#include "Algorithm.h"

#include <iostream>
#include <algorithm>

double Algorithm::Mean(const vector<int>& data) {
	int sum = 0;	
	for (int i = 0; i < data.size(); i++) {
		const int& record = data[i];
		sum += record;

	}
	return double(sum) / double(data.size()); //static_cast - konwersja typu
}

double Algorithm::StdDev(const vector<int>& data) {
	auto mean = Mean(data);

	double dev = 0;
	for (int i = 0; i < data.size(); i++) {
		const int& record = data[i];
		dev += pow(record - mean, 2);
	}

	return sqrt(dev / (data.size() - 1));
}

int Algorithm::Median(vector<int>& data) {
	if (data.size() == 0) return 0;

	sort(data.begin(), data.end());

	int medianPoint = data.size() / 2;

	if (medianPoint % 2 == 1) {
		return data[medianPoint];
	}
	else {
		return (data[medianPoint - 1] + data[medianPoint]) / 2;
	}
}