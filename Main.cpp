#include <iostream>
#include "Vector.hpp"

using namespace std;

int main() {
	Vector<float> v1{ 1.0f, 2.0f, 3.0f };
	Vector<float> v2{ 4.0f, 5.0f, 6.0f };

	Vector<float> v3 = v1 + v2;

	cout << "v1 = " << v1 << endl;
	cout << "v2 = " << v2 << endl;
	cout << "v1 + v2 = " << v3 << endl;
	return 0;
}