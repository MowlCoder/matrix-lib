#pragma once

#include <iostream>
#include <cstdint>

typedef uint8_t byte;

const byte MATRIX_DEFAULT_SIZE = 3;

class Matrix {
private:
    byte _size{};

    void init(byte size);
    void init(byte size, double **value);

public:
    double **_value{};

    Matrix();
    explicit Matrix(int size);
    Matrix(double **value, int size);
    Matrix(const Matrix&);
    ~Matrix();

    Matrix operator+(const Matrix& m) const;
    Matrix operator-(const Matrix& m) const;
    Matrix operator*(const Matrix& m) const;
    Matrix add(const Matrix& m) const;
    Matrix subtract(const Matrix& m) const;
    Matrix multiply(const Matrix& m) const;
    Matrix power(double number); // TODO: Implement power function
    void valueAdd(double number) const;
    void valueSubtract(double number) const;
    void valueMultiply(double number) const;
    Matrix transposition() const;
    Matrix reverse() const;
    Matrix minor() const;
    Matrix triangleView(); // TODO: Implement function to get triangle view of matrix
    double rank(); // TODO: Implement get matrix rank function
    double getDeterminant() const;
    int getSize() const;
    void show() const;
    std::string toString() const;
    std::string toPlaneString() const;
    std::string toDebugString() const;
};
