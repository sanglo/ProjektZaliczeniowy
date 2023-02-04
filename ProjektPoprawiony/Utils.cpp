#include "Utils.h"

#include <sstream>

vector<string> SplitLine(const string& line, char delimeter) {

	vector<string>fields;

	stringstream sstr{ line };
	string field;
	while (getline(sstr, field, delimeter)) {
		fields.push_back(field);
	}
	return fields;

}

//
bool EndsWith(const  string& fullString, const  string& ending) {
	if (fullString.size() >= ending.size()) {
		return (fullString.compare(fullString.size() - ending.size(), ending.size(), ending) == 0);
	}
	else {
		return false;
	}
}





int StrToInt(const string& str) {
	int i{};
	i = stoi(str);
	return i;
	
}

void PlotData(const  vector<int>& data) {
	FILE* pipe = _popen("gnuplot", "w");
	if (pipe == nullptr) {
		cout<<"[ERROR] _popen() returned a nullptr";
	}

	// gnuplot options
	fprintf(pipe, "set term wx\n");
	fprintf(pipe, "plot '-' with points\n");

	for (const auto& elem : data) {
		fprintf(pipe, "%d\n", elem);
	}

	fprintf(pipe, "%s\n", "e");
	fflush(pipe);

	// wait for key press
	 cin.clear();
	 cin.get();

	_pclose(pipe);
}
void PlotData1(const  vector<int>& data) {
	FILE* pipe = _popen("gnuplot", "w");
	if (pipe == nullptr) {
		cout << "[ERROR] _popen() returned a nullptr";
	}

	// gnuplot options
	fprintf(pipe, "set term wx\n");
	fprintf(pipe, "plot '-' with lines\n");

	for (const auto& elem : data) {
		fprintf(pipe, "%d\n", elem);
	}

	fprintf(pipe, "%s\n", "e");
	fflush(pipe);

	// wait for key press
	cin.clear();
	cin.get();

	_pclose(pipe);
}