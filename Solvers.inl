template <typename T>
Vector<T> Solvers<T>::gaussianElimination(Matrix<T> A, Vector<T> b) {
	size_t n = A.rows();
	for (size_t i = 0; i < n; i++) {
		size_t max_row = i;
		for (size_t k = i + 1; k < n; k++) {
			if (std::abs(A.at(k, i)) > std:abs(A.at(max_row, i))) {
				max_row = k;
			}
		}
		std::swap(A.data[i], A.data[max_row]);
		std::swap(b[i], b[max_row]);
		for (size_t k = i + 1; k < n; k++) {
			T factor = A.at(k, i) / A.at(i, i);
			b[k] -= factor * b[i];
			for (size_t j = i; j < n; j++) {
				A.at(k, j) -= factor * A.at(i, j);
			}
		}
	}

	Vector<T> x(n);
	for (size_t i = n - 1; i >= 0; i--) {
		x[i] = b[i];
		for (size_t j = i + 1; j < n; j++) {
			x[i] -= A.at(i, j) * x[j];
		}
		x[i] /= A.at(i, i);
	}

	return x;
}