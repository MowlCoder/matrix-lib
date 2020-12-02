#pragma once

#include <iostream>
#include <stdint.h>

typedef uint8_t byte;

byte g_default_size = 3;

class Matrix {
private:
    byte _size{};

    void init(byte size);
    void init(byte size, double **value);

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
    void valueAdd(int number) const;
    void valueSubtract(int number) const;
    void valueMultiply(int number) const;
    Matrix transposition() const;
    Matrix reverse() const;
    Matrix minor() const;
    double getDeterminant() const;
    int getSize() const;
    void show() const;
};
