#pragma once

#include <vector>
using namespace std;

class Algorithm {
public:
	static double Mean(const vector<int>& data);
	static double StdDev(const vector<int>& data);
	static int Median(vector<int> data); // bez const bo modyfukujemy dane(sortujemy)
};