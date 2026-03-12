template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) : data(rows, std::vector<T>(cols)) {}

template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> init) {
	if (init.size() == 0) 
		throw std::invalid_argument("Matrix must be non-empty");

	auto expected_size = init.begin()->size();

	for (const auto& row : init) {
		if (row.size() != expected_size) {
			throw std::invalid_argument("All rows must have the same number of columns");
		}
		data.emplace_back(row); 
	}
}

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
		throw std::invalid_argument("Matrix dimensions must match for multiplication.");

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
Matrix<T> Matrix<T>::identity(size_t n) {
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

	size_t n = rows();

	Matrix<T> augmented(n, 2 * n);

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			augmented.at(i, j) = at(i, j);
			augmented.at(i, j + n) = (i == j) ? static_cast<T>(1) : static_cast<T>(0);
		}
	}

	for (size_t i = 0; i < n; i++) {
		T pivot = augmented.at(i, i);
		if (pivot == static_cast<T>(0))
			throw std::runtime_error("Matrix is singular and cannot be inverted.");
		for (size_t j = 0; j < 2 * n; j++) {
			augmented.at(i, j) /= pivot;
		}
		for (size_t k = 0; k < n; k++) {
			if (k == i) continue;
			T factor = augmented.at(k, i);
			for (size_t j = 0; j < 2 * n; j++) {
				augmented.at(k, j) -= factor * augmented.at(i, j);
			}
		}
	}

	Matrix<T> inverse(n, n);
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			inverse.at(i, j) = augmented.at(i, j + n);
		}
	}

	return inverse;
}