#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "matrix.h"
#include "../validate/validate.h"
#include "../random/random.h"

Matrix::Matrix() {
    std::cout << "Constructor: " << this << '\n';
    init(MATRIX_DEFAULT_SIZE);
}

void Matrix::init(byte size) {
    _size = size;
    _value = new double*[size];

    for (byte i = 0; i < size; i++) {
        _value[i] = new double[size];
        memset(_value[i], 0, size * sizeof(double));
    }
}

void Matrix::init(byte size, double **value) {
    init(size);

    for (byte i = 0; i < size; i++) {
        for (byte j = 0; j < size; j++) {
            _value[i][j] = value[i][j];
        }
    }
}

Matrix::Matrix(int size) {
    std::cout << "Constructor: " << this << '\n';
    init(size);
}

Matrix::Matrix(double **value, int size) {
    std::cout << "Constructor: " << this << '\n';
    init(size, value);
}

Matrix::Matrix(const Matrix &m) {
    init(m._size, m._value);
    std::cout << "Copy Constructor: " << this << '\n';
}

Matrix::~Matrix() {
    std::cout << "Deconstruct: " << this << '\n';

    for (byte i = 0; i < _size; i++) {
        delete _value[i];
    }

    delete[] _value;
}

Matrix Matrix::operator+(const Matrix& m) const {
    Matrix result = add(m);
    return result;
}

Matrix Matrix::add(const Matrix& m) const {
    Matrix result = Matrix(_size);

    for (byte i = 0; i < _size; i++) {
        for (byte j = 0; j < _size; j++) {
            result._value[i][j] += _value[i][j] + m._value[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& m) const {
    Matrix result = subtract(m);
    return result;
}

Matrix Matrix::subtract(const Matrix& m) const {
    Matrix result = Matrix(_size);

    for (byte i = 0; i < _size; i++) {
        for (byte j = 0; j < _size; ++j) {
            result._value[i][j] += _value[i][j] - m._value[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& m) const {
    Matrix result = multiply(m);
    return result;
}

Matrix Matrix::multiply(const Matrix& m) const {
    Matrix result = Matrix(_size);

    for (byte i = 0; i < _size; i++) {
        for (byte j = 0; j < _size; j++) {
            for (byte x = 0; x < _size; x++) {
                result._value[i][x] += _value[i][j] * m._value[j][x];
            }
        }
    }

    return result;
}

void Matrix::valueAdd(double number) const {
    for (byte i = 0; i < _size; i++) {
        for (byte j = 0; j < _size; j++) {
            _value[i][j] += number;
        }
    }
}

void Matrix::valueSubtract(double number) const {
    for (byte i = 0; i < _size; i++) {
        for (byte j = 0; j < _size; j++) {
            _value[i][j] -= number;
        }
    }
}

void Matrix::valueMultiply(double number) const {
    for (byte i = 0; i < _size; i++) {
        for (byte j = 0; j < _size; j++) {
            _value[i][j] *= number;
        }
    }
}

Matrix Matrix::transposition() const {
    Matrix result = Matrix(_size);

    for (byte i = 0; i < _size; i++) {
        for (byte j = 0; j < _size; j++) {
            result._value[i][j] = _value[j][i];
        }
    }

    return result;
}

Matrix Matrix::reverse() const {
    double determinant = this->getDeterminant();
//    validate(determinant != 0, nullptr, "Determinant is zero")

    if (determinant == 0) {
        std::cout << "Determinant is zero\n";
        return Matrix();
    }

    Matrix initMatrix = this->minor();

    if (_size == 2) {
        initMatrix._value[0][1] *= -1;
        initMatrix._value[1][0] *= -1;
    }
    else if (_size == 3) {
        initMatrix._value[0][1] *= -1;
        initMatrix._value[1][0] *= -1;
        initMatrix._value[1][2] *= -1;
        initMatrix._value[2][1] *= -1;
    }

    Matrix tMatrix = initMatrix.transposition();

    for (byte i = 0; i < _size; i++) {
        for (byte j = 0; j < _size; j++) {
            tMatrix._value[i][j] /= determinant;
        }
    }

    return tMatrix;
}

Matrix Matrix::minor() const {
    Matrix minorMatrix = Matrix(_size);

    if (_size == 2) {
        for (byte i = 0; i < _size; i++) {
            for (byte j = 0; j < _size; j++) {
                minorMatrix._value[i][j] = _value[!i][!j];
            }
        }
    }
    else if (_size == 3) {
        for (byte i = 0; i < _size; i++) {
            for (byte j = 0; j < _size; j++) {
                int aI = (i == 0) ? 1 : 0;
                int bI = (i == 2) ? 1 : 2;
                int aJ = (j == 0) ? 1 : 0;
                int bJ = (j == 2) ? 1 : 2;
                minorMatrix._value[i][j] = _value[aI][aJ] * _value[bI][bJ] - _value[bI][aJ] * _value[aI][bJ];
            }
        }
    }

    return minorMatrix;
}

double Matrix::getDeterminant() const {
    if (_size == 2) {
        return (_value[0][0] * _value[1][1]) - (_value[0][1] * _value[1][0]);
    }
    if (_size == 3) {
        return (_value[0][0] * _value[1][1] * _value[2][2]) +
                (_value[2][0] * _value[0][1] * _value[1][2]) +
                (_value[1][0] * _value[2][1] * _value[0][2]) -
                (_value[2][0] * _value[1][1] * _value[0][2]) -
                (_value[1][0] * _value[0][1] * _value[2][2]) -
                (_value[0][0] * _value[1][2] * _value[2][1]);
    }
    if (_size >= 4) {
        Matrix finalMatrix = Matrix(_size);

        for (byte i = 0; i < _size; i++) {
            for (byte j = 0; j < _size; j++) {
                finalMatrix._value[i][j] = _value[i][j];
            }
        }

        for (byte i = 1; i < _size; i++) {
            double multiplier = fabs(finalMatrix._value[i][0] / finalMatrix._value[0][0]) * ((finalMatrix._value[0][0] >= 0) ? -1 : 1);
            for (byte j = 0; j < _size; j++) {
                finalMatrix._value[i][j] += finalMatrix._value[0][j] * multiplier;
            }
        }

        for (byte i = 2; i < _size; i++) {
            double multiplier = fabs(finalMatrix._value[i][1] / finalMatrix._value[1][1]) * ((finalMatrix._value[1][1] >= 0) ? -1 : 1);
            for (byte j = 1; j < _size; j++) {
                finalMatrix._value[i][j] += finalMatrix._value[1][j] * multiplier;
            }
        }

        double multiplier = fabs(finalMatrix._value[3][2] / finalMatrix._value[2][2]) * ((finalMatrix._value[2][2] >= 0) ? -1 : 1);
        for (byte i = 2; i < _size; i++) {
            finalMatrix._value[3][i] += finalMatrix._value[2][i] * multiplier;
        }

        double result = finalMatrix._value[0][0] * finalMatrix._value[1][1] * finalMatrix._value[2][2] * finalMatrix._value[3][3];

        return result;
    }
}

int Matrix::getSize() const {
    return _size;
}

void Matrix::randomizeValues(const int minValue, const int maxValue) {
    for (byte i = 0; i < _size; i++) {
        for (byte j = 0; j < _size; j++) {
            _value[i][j] = getRandomNumber(minValue, maxValue);
        }
    }
}

void Matrix::show() const {
    for (byte i = 0; i < _size; i++) {
        for (byte j = 0; j < _size; j++) {
            std::cout << _value[i][j] << '\t';
        }
        std::cout << '\n';
    }
}

std::string Matrix::toString() const {
    std::string result;

    for (byte i = 0; i < _size; i++) {
        for (byte j = 0; j < _size; j++) {
            result += std::to_string(_value[i][j]);
            result += '\t';
        }

        result += '\n';
    }

    return result;
}

std::string Matrix::toPlaneString() const {
    std::string result = "[";

    for (byte i = 0; i < _size; i++) {
        result += "[";

        for (byte j = 0; j < _size; j++) {
            result += std::to_string(_value[i][j]);

            if (j + 1 != _size) {
                result += ',';
            }
        }

        result += ']';
        if (i + 1 != _size) {
            result += ',';
        }
    }

    result += ']';

    return result;
}

std::string Matrix::toDebugString() const {
    std::string result = "Value: ";
    result += this->toPlaneString();
    result += " Size: ";
    result += std::to_string(_size);

    return result;
}