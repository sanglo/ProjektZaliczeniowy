#pragma once
using namespace std;
#include <vector>

class Algorithm {
public:
	static double Mean(const vector<int>& data);
	static double StdDev(const vector<int>& data);
	static int Median(vector<int> data); // bez const bo modyfukujemy dane(sortujemy)

};