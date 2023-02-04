#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Utils.h"
using namespace std;

class Plik_1 {
private:
	Plik_1() = default;
public:
	static Plik_1 FromFields(const vector<string>& fields);

	int pneumonia;
	int age;

};