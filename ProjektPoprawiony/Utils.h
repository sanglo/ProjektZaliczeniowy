#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool EndsWith(const string& fullString, const string& ending);
int StrToInt(const string& sv);
void PlotData(const vector<int>& data);
void PlotData1(const vector<int>& data);
vector<string> SplitLine(const string& line, char delim = ',');