#include "transformMatrix.h"

transformMatrix::transformMatrix(stringstream& stream)
	:N(0), CONSTANT_ZERO(0), CONSTANT_ELSE(0)
{
	int temp;
	while (stream >> temp) {
		input.push_back(temp);
		N++;
	}
	if (N > 0) {
		CONSTANT_ZERO = sqrt(1 / N);
		CONSTANT_ELSE = sqrt(2 / N);
	}
	vector<int> colWidth(N);
	C = vector<vector<int>>(N, colWidth); //Set transform matrix dimensions
	initialize();
}

// Set matrix to zeroes
void transformMatrix::initialize()
{
	row = C.begin();
	while (row != C.end()) {
		col = row->begin();
		while (col != row->end()) {
			*col = 0;
			col++;
		}
		row++;
	}
}

void transformMatrix::print()
{
	row = C.begin();
	while (row != C.end()) {
		col = row->begin();
		cout << "[";
		while (col != row->end()) {
			cout << setw(3) << *col << " ";
			col++;
		}
		cout << "]\n";
		row++;
	}
}
