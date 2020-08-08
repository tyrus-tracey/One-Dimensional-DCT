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
	void initialize();
	void print();

private:
	int N;
	double CONSTANT_ZERO;
	double CONSTANT_ELSE;
	vector<vector<int>> C; //transform matrix
	vector<int> input;

	vector<vector<int>>::iterator row;
	vector<int>::iterator col;
};

