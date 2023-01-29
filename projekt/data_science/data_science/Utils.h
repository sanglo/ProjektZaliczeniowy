#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <charconv>
using namespace std;


class Date {
public:
	int day{}, month{}, year{};

	Date(); //konstruktor domyœlny
	Date(const string dateStr);
	Date& operator=(const string dateStr);
private:
	void Set(const string dateStr);

};

int SvToInt(const string sv);
void PlotData(const vector<int>& data);