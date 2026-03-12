#pragma once
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Vector.hpp"
#include <vector>

template <typename T>
class Matrix {
public:
	std::vector<vector<T>> data;

	Matrix(size_t rows, size_t cols);
	T& at(size_t r, size_t c);
	const T& at(size_t r, size_t c) const;
	size_t rows() const;
	size_t cols() const;

	Matrix operator+(const Matrix& other) const;
	Matrix operator*(const Matrix& other) const;

	Vector<T> operator*(const Vector<T>& v) const;

	Matrix transpose() const;
	static Matrix identity(size_t n);

	Matrix inverse() const;
	T determinant() const;

	friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& m) {
		os << "[";
		for (size_t i = 0; i < m.rows(); i++) {
			os << "[";
			for (size_t j = 0; j < m.cols(); j++) {
				os << m.data[i][j];
				if (j < m.cols() - 1)
					os << ", ";
			}
			os << "]";
			if (i < m.rows() - 1)
				os << std::endl;
		}
		os << "]";
	}
};

#include "Matrix.inl"

#endif // !MATRIX_HPP
