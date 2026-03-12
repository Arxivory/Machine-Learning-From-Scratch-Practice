#include <iostream>
#include "Vector.hpp"
#include "Matrix.hpp"

using namespace std;

int main() {
	cout << "Testing Vector class: " << endl;
	Vector<float> v1{ 1.0f, 2.0f, 3.0f };
	Vector<float> v2{ 4.0f, 5.0f, 6.0f };

	Vector<float> v3 = v1 + v2;

	cout << "v1 = " << v1 << endl;
	cout << "v2 = " << v2 << endl;
	cout << "v1 + v2 = " << v3 << endl;

	cout << "v1 dot v2 = " << v1.dot(v2) << endl;
	cout << "v1 norm1 = " << v1.norm1() << endl;
	cout << "v2 norm1 = " << v2.norm1() << endl;

	cout << "v1 * 2 = " << v1 * 2.0f << endl;


	cout << "Testing Matrix class: " << endl;
	Matrix<float> m1{
		{1.0f, 2.0f, 3.0f},
		{4.0f, 5.0f, 6.0f},
		{7.0f, 8.0f, 9.0f}
	};

	Matrix<float> m2{
		{9.0f, 8.0f, 7.0f},
		{6.0f, 5.0f, 4.0f},
		{3.0f, 2.0f, 1.0f}
	};

	Matrix<float> m3 = m1 + m2;

	cout << "m1 = " << endl << m1 << endl;
	cout << "m2 = " << endl << m2 << endl;
	cout << "m1 + m2 = " << endl << m3 << endl;

	return 0;
}