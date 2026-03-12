template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) : data(rows, vector<T>(cols)) {}

template <typename T>
T& Matrix<T>::at(size_t r, size_t c) {
	return data[r][c];
}

template <typename T>
const T& Matrix<T>::at(size_t r, size_t c) const {
	return data[r][c];
}

template <typename T>
size_t Matrix<T>::rows() const {
	return data.size();
}

template <typename T>
size_t Matrix<T>::cols() const {
	return data.empty() ? 0 : data[0].size();
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& other) const {
	if (rows() != other.rows() || cols() != other.cols())
		throw std::invalid_argument("Matrix dimensions must match for addition.");

	Matrix result(rows(), cols());
	for (size_t i = 0; i < rows(); i++) {
		for (size_t j = 0; j < cols(); j++) {
			result.at(i, j) = at(i, j) + other.at(i, j);
		}
	}
	
	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& other) const {
	if (cols() != other.rows())
		throw std:invalid_argument("Matrix dimensions must match for multiplication.");

	Matrix result(rows(), other.cols());
	for (size_t i = 0; i < rows(); i++) {
		for (size_t j = 0; j < other.cols(); j++) {
			for (size_t k = 0; k < cols(); k++) {
				result.at(i, j) += at(i, k) * other.at(k, j);
			}
		}
	}

	return result;
}

template <typename T>
Vector<T> Matrix<T>::operator*(const Vector<T>& v) const {
	if (cols() != v.size())
		throw std::invalid_argument("Matrix columns must match vector size for multiplication.");

	Vector<T> result(rows());
	for (size_t i = 0; i < rows(); i++) {
		for (size_t j = 0; j < cols(); j++) {
			result[i] += at(i, j) * v[j];
		}
	}

	return result;
}

template <typename T>
Matrix<T> Matrix<T>::transpose() const {
	Matrix result(cols(), rows());
	for (size_t i = 0; i < rows(); i++) {
		for (size_t j = 0; j < cols(); j++) {
			result.at(j, i) = at(i, j);
		}
	}

	return result;
}

template <typename T>
static Matrix<T> Matrix<T>::identity(size_t n) {
	Matrix result(n, n);
	for (size_t i = 0; i < n; i++) {
		result.at(i, i) = static_cast<T>(1);
	}
	return result;
}

template <typename T>
Matrix<T> Matrix<T>::inverse() const {
	if (rows() != cols())
		throw std::invalid_argument("Only square matrices can be inverted.");

	Matrix result(rows(), cols());

	std::vector<vector<T>> copyData = data;

	T temp;

	for (size_t i = rows() - 1; i > 0; i--) {
		if (at(i - 1, 0) < at(i, 0)) {
			std::vector<T> tempRow = copyData[i - 1];
			copyData[i - 1] = copyData[i];
			copyData[i] = tempRow;
		}
	}

	for (size_t i = 0; i < rows(); i++) {
		for (size_t j = 0; j < cols(); j++) {
			if (i != j) {
				temp = at(j, i) / at(i, i);

				for (size_t k = 0; k < cols(); k++) {
					at(j, k) -= at(i, k) * temp;
				}
			}
		}
	}

	for (size_t i = 0; i < rows(); i++) {
		temp = at(i, i);

		for (size_t j = 0; j < cols(); j++) {
			result.at(i, j) = at(i, j) / temp;
		}
	}

	return result;
}