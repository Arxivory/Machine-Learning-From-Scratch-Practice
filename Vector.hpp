#pragma once
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <initializer_list>
#include <vector>
#include <iostream>
#include <cmath>

template <typename T>
class Vector {
public:
    std::vector<T> data;

    Vector(size_t n);
    Vector(std::initializer_list<T> init);

    T& operator[](size_t i);
    const T& operator[](size_t i) const;
    size_t size() const;

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(T scalar) const;
    T dot(const Vector& other) const;

    T norm1() const;
    T norm2() const;

    void fill(T value);

    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
        os << "[";
        for (size_t i = 0; i < v.size(); i++) {
            os << v.data[i];
            if (i < v.size() - 1)
                os << ", ";
        }
        os << "]";
        return os;
    }
};

#include "Vector.inl"

#endif // VECTOR_HPP