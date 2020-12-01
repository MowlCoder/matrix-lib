#pragma once

#include <iostream>

class Matrix {
private:
    int _size{};

    void init(int size);
    void init(int size, double **value);

public:
    double **_value{};

    Matrix();
    Matrix(int size);
    Matrix(double **value, int size);
    Matrix(const Matrix&);
    ~Matrix();

    Matrix operator+(const Matrix& m) const;
    Matrix operator-(const Matrix& m) const;
    Matrix operator*(const Matrix& m) const;
    Matrix add(const Matrix& m) const;
    Matrix subtract(const Matrix& m) const;
    Matrix multiply(const Matrix& m) const;
    Matrix transposition() const;
    Matrix reverse() const;
    Matrix minor() const;
    double getDeterminant() const;
    int getSize() const;
    void show() const;
};
