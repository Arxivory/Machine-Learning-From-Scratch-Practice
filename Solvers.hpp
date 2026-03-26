#pragma once
#ifndef SOLVERS_H
#define SOLVERS_H

#include "Matrix.hpp"
#include "Vector.hpp"

template <typename T>
class Solvers {
public:
	static Vector<T> gaussianElimination(Matrix<T> A, Vector<T> b);
	static Vector<T> gaussJordanElimination(Matrix<T> A, Vector<T> b);
	static Vector<T> luDecomposition(Matrix<T> A, Vector<T> b);
	static Vector<T> choleskyDecomposition(Matrix<T> A, Vector<T> b);
	static Vector<T> qrDecomposition(Matrix<T> A, Vector<T> b);
};

#include "Solvers.inl"

#endif // !SOLVERS_H

