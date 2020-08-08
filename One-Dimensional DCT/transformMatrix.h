#pragma once
#include <sstream>
#include <math.h>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class transformMatrix
{
public:
	transformMatrix(stringstream& stream);
	void print();

private:
	void initialize();

	int N;
	double CONSTANT_ZERO;
	double CONSTANT_ELSE;
	vector<vector<int>> C; //transform matrix
	vector<int> input;

	vector<vector<int>>::iterator row;
	vector<int>::iterator col;
};

