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

	Matrix<float> m8{
		{1.0f, 0.0f, 0.0f},
		{0.0f, 2.0f, 0.0f},
		{0.0f, 0.0f, 1.0f}
	};

	Matrix<float> m3 = m1 + m2;
	Matrix<float> m4 = m1 * m2;
	Vector<float> v4 = m1 * v1;
	Matrix<float> m5 = m1.transpose();
	Matrix<float> m6 = Matrix<float>::identity(3);

	cout << "m1 = " << endl << m1 << endl;
	cout << "m2 = " << endl << m2 << endl;
	cout << "m1 + m2 = " << endl << m3 << endl;
	cout << "m1 * m2 = " << endl << m4 << endl;
	cout << "m1 * v1 = " << v4 << endl;
	cout << "m1 transpose = " << endl << m5 << endl;
	cout << "Identity matrix = " << endl << m6 << endl;
	cout << "m8^-1 = " << endl << m8.inverse() << endl;

	
	
	return 0;
}