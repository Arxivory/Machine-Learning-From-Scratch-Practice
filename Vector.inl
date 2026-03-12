template <typename T>
Vector<T>::Vector(size_t n) : data(n) {}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> init) : data(init) {}

template <typename T>
T& Vector<T>::operator[](size_t i) {
    return data[i];
}

template <typename T>
const T& Vector<T>::operator[](size_t i) const {
    return data[i];
}

template <typename T>
size_t Vector<T>::size() const {
    return data.size();
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector& other) const {
    Vector result(size());
    for (size_t i = 0; i < size(); i++)
        result[i] = data[i] + other[i];
    return result;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector& other) const {
    Vector result(size());
    for (size_t i = 0; i < size(); i++)
        result[i] = data[i] - other[i];
    return result;
}

template <typename T>
Vector<T> Vector<T>::operator*(T scalar) const {
    Vector result(size());
    for (size_t i = 0; i < size(); i++)
        result[i] = data[i] * scalar;
    return result;
}

template <typename T>
T Vector<T>::dot(const Vector& other) const {
    T result = 0;
    for (size_t i = 0; i < size(); i++)
        result += data[i] * other[i];
    return result;
}

template <typename T>
T Vector<T>::norm1() const {
    T result = 0;
    for (size_t i = 0; i < size(); i++)
        result += std::abs(data[i]);
    return result;
}

template <typename T>
T Vector<T>::norm2() const {
    T result = 0;
    for (size_t i = 0; i < size(); i++)
        result += data[i] * data[i];
    return std::sqrt(result);
}

template <typename T>
void Vector<T>::fill(T value) {
    for (size_t i = 0; i < size(); i++)
        data[i] = value;
}