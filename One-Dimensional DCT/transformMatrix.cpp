#include "transformMatrix.h"
#define _USE_MATH_DEFINES
#include <math.h>

transformMatrix::transformMatrix(stringstream& stream)
	:N(0), a_ZERO(0), a_ELSE(0)
{
	int temp;
	while (stream >> temp) {
		input.push_back(temp);
		N++;
	}
	if (N > 10) {
		cerr << "ERROR: Input greater than 10 integers.\n\n";
		return;
	}
	if (N > 0) {
		a_ZERO = sqrt(1.0 / N);
		a_ELSE = sqrt(2.0 / N);
	}
	vector<double> colWidth(N);
	C = vector<vector<double>>(N, colWidth); //Set transform matrix dimensions
	generateMatrix();
	generateDCT();
	round();
}

// Generate C(i,j) matrix
void transformMatrix::generateMatrix()
{
	double a = a_ZERO;
	double temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp = (2.0 * j) + 1;
			temp *= (PI * i);
			temp /= (double(N) * 2);
			temp = cos(temp); 
			temp *= a;
			C[i][j] = temp;
		}
		a = a_ELSE;
	}
}

// One-dimensional discrete cosine transform
void transformMatrix::generateDCT()
{
	int i;
	double temp;
	double sum;
	double Cu = a_ZERO;
	vector<double>::iterator iter;
	for (int u = 0; u < N; u++) {
		iter = input.begin();
		sum = 0, i = 0;
		while (iter != input.end()) {
			temp = (2.0 * i) + 1;
			temp *= (PI * u);
			temp /= (double(N)*2);
			temp = cos(temp);
			temp *= *iter;
			sum += temp;
			i++, iter++;
		}
		F.push_back(Cu * sum);
		Cu = a_ELSE;
	}
}

// Set miniscule values to zeroes
void transformMatrix::round()
{
	row = C.begin();
	while (row != C.end()) {
		col = row->begin();
		while (col != row->end()) {
			if (abs(*col) < 0.00001) {
				*col = 0;
			}
			col++;
		}
		row++;
	}

	col = F.begin();
	while (col != F.end()) {
		if (abs(*col) < 0.00001) {
			*col = 0;
		}
		col++;
	}
}

void transformMatrix::print()
{
	if (C.empty()) {
		return;
	}
	cout.precision(4);
	cout << "Ci,j:\n";
	row = C.begin();
	while (row != C.end()) {
		col = row->begin();
		cout << "  [";
		while (col != row->end()) {
			cout << setw(8) << *col << " ";
			col++;
		}
		cout << "]\n";
		row++;
	}
	cout.precision(7);
	cout << "Output:\n" << "  ";
	col = F.begin();
	while (col != F.end()) {
		cout << *col << "  ";
		col++;
	}
	cout << endl << endl;
}
