#include <iostream>
#include <cstring>
#include <cmath>
#include "matrix.h"
#include "../validate/validate.h"

double** matrixAdd(double** firstMatrix, double** secondMatrix, size_t matrixSize) {
    double** resultMatrix = matrixInit(matrixSize);

    validate(firstMatrix != nullptr, nullptr, "First matrix is null")
    validate(secondMatrix != nullptr, nullptr, "Second matrix is null")
    validate(resultMatrix != nullptr, nullptr, "Final matrix is null")

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            resultMatrix[i][j] += firstMatrix[i][j] + secondMatrix[i][j];
        }
    }

    return resultMatrix;
}

double** matrixSubtraction(double** firstMatrix, double** secondMatrix, size_t matrixSize) {
    double** resultMatrix = matrixInit(matrixSize);

    validate(firstMatrix != nullptr, nullptr, "First matrix is null")
    validate(secondMatrix != nullptr, nullptr, "Second matrix is null")
    validate(resultMatrix != nullptr, nullptr, "Final matrix is null")

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; ++j) {
            resultMatrix[i][j] += firstMatrix[i][j] - secondMatrix[i][j];
        }
    }

    return resultMatrix;
}

double** matrixMulti(double** firstMatrix, double** secondMatrix, size_t matrixSize) {
    double** resultMatrix = matrixInit(matrixSize);

    validate(firstMatrix != nullptr, nullptr, "First matrix is null")
    validate(secondMatrix != nullptr, nullptr, "Second matrix is null")
    validate(resultMatrix != nullptr, nullptr, "Final matrix is null")

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            for (int x = 0; x < matrixSize; x++) {
                resultMatrix[i][x] += firstMatrix[i][j] * secondMatrix[j][x];
            }
        }
    }

    return resultMatrix;
}

double matrixDeterminant(double** m, size_t matrixSize) {
    validate(m != nullptr, 0, "Matrix is null")

    if (matrixSize == 2) {
        return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
    }
    if (matrixSize == 3) {
        return (m[0][0] * m[1][1] * m[2][2]) + (m[2][0] * m[0][1] * m[1][2]) + (m[1][0] * m[2][1] * m[0][2])
               - (m[2][0] * m[1][1] * m[0][2]) - (m[1][0] * m[0][1] * m[2][2]) - (m[0][0] * m[1][2] * m[2][1]);
    }
    if (matrixSize >= 4) {
        double** finalMatrix = matrixInit(matrixSize);

        for (size_t i = 0; i < matrixSize; i++) {
            for (size_t j = 0; j < matrixSize; j++) {
                finalMatrix[i][j] = m[i][j];
            }
        }

        for (size_t i = 1; i < matrixSize; i++) {
            double multiplier = fabs(finalMatrix[i][0] / finalMatrix[0][0]) * ((finalMatrix[0][0] >= 0) ? -1 : 1);
            for (size_t j = 0; j < matrixSize; j++) {
                finalMatrix[i][j] += finalMatrix[0][j] * multiplier;
            }
        }

        for (size_t i = 2; i < matrixSize; i++) {
            double multiplier = fabs(finalMatrix[i][1] / finalMatrix[1][1]) * ((finalMatrix[1][1] >= 0) ? -1 : 1);
            for (size_t j = 1; j < matrixSize; j++) {
                finalMatrix[i][j] += finalMatrix[1][j] * multiplier;
            }
        }

        double multiplier = fabs(finalMatrix[3][2] / finalMatrix[2][2]) * ((finalMatrix[2][2] >= 0) ? -1 : 1);
        for (size_t i = 2; i < matrixSize; i++) {
            finalMatrix[3][i] += finalMatrix[2][i] * multiplier;
        }

        double result = finalMatrix[0][0] * finalMatrix[1][1] * finalMatrix[2][2] * finalMatrix[3][3];

        matrixDestroy(finalMatrix, matrixSize);
        return result;
    }

    return 0;
}

double** matrixTransposition(double** matrix, size_t matrixSize) {
    validate(matrix != nullptr, nullptr, "Matrix is null")

    double** resultMatrix = matrixInit(matrixSize);

    for (size_t i = 0; i < matrixSize; i++) {
        for (size_t j = 0; j < matrixSize; j++) {
            resultMatrix[i][j] = matrix[j][i];
        }
    }

    return resultMatrix;
}

double** matrixReverse(double** matrix, size_t matrixSize) {
    validate(matrix != nullptr, nullptr, "Matrix is null")

    double determinant = matrixDeterminant(matrix, matrixSize);
    validate(determinant != 0, nullptr, "Determinant is zero")

    double** initMatrix = matrixMinor(matrix, matrixSize);

    if (matrixSize == 2) {
        initMatrix[0][1] *= -1;
        initMatrix[1][0] *= -1;

        double** tMatrix = matrixTransposition(initMatrix, matrixSize);

        for (size_t i = 0; i < matrixSize; i++) {
            for (size_t j = 0; j < matrixSize; j++) {
                tMatrix[i][j] /= determinant;
            }
        }

        return tMatrix;
    }

    matrixDestroy(initMatrix, matrixSize);
}

double** matrixMinor(double** matrix, size_t matrixSize) {
    validate(matrix != nullptr, nullptr, "Matrix is null")

    double** minorMatrix = matrixInit(matrixSize);

    if (matrixSize == 2) {
        for (size_t i = 0; i < matrixSize; i++) {
            for (size_t j = 0; j < matrixSize; j++) {
                minorMatrix[i][j] = matrix[!i][!j];
            }
        }
    }

    return minorMatrix;
}

double** matrixInit(size_t matrixSize) {
    validate(matrixSize >= 2 && matrixSize <= 6, nullptr, "Matrix size should be between 2 and 6")

    double** result = new double*[matrixSize];

    for (size_t i = 0; i < matrixSize; i++) {
        result[i] = new double[matrixSize];
        memset(result[i], 0, matrixSize * sizeof(double));
    }

    return result;
}

void matrixDestroy(double** matrix, size_t matrixSize) {
    for (size_t i = 0; i < matrixSize; i++) {
        delete matrix[i];
    }

    delete matrix;
}

void matrixDisplay(double** matrix, size_t matrixSize) {
    for (size_t i = 0; i < matrixSize; i++) {
        for (size_t j = 0; j < matrixSize; j++) {
            std::cout << matrix[i][j] << '\t';
        }

        std::cout << '\n';
    }
}