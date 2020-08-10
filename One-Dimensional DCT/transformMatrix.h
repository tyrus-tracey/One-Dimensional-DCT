#pragma once
#include <sstream>
#include <cmath>
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
	void generateMatrix();
	void generateDCT();
	void round();

	int N;
	double a_ZERO;
	double a_ELSE;
	const double PI = 3.14159265358979323846;
	vector<vector<double>> C; //C(i,j) matrix
	vector<double> F; // 1D Transform output
	vector<double> input;

	vector<vector<double>>::iterator row;
	vector<double>::iterator col;
};

