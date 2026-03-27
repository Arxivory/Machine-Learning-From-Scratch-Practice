#include <iostream>
#include "Vector.hpp"
#include "Matrix.hpp"
#include "Solvers.hpp"

using namespace std;

int main() {
	//testing the solver using gaussian elimination method.
	Matrix<float> A{
		{1.0f, 2.0f, 1.0f},
		{3.0f, 8.0f, 1.0f},
		{0.0f, 4.0f, 1.0f}
	};

	Vector<float> b{ 2.0f, 12.0f, 2.0f };

	Vector<float> x = Solvers<float>::gaussianElimination(A, b);
	cout << "Solution using Gaussian Elimination: " << x << endl;

	return 0;
}