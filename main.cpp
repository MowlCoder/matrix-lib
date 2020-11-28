#include <iostream>
#include "./include/matrix/matrix.h"

int main() {
    const unsigned int matrixSize = 3;
    double** firstMatrix = matrixInit(matrixSize);

    firstMatrix[0][0] = 4;
    firstMatrix[0][1] = 2;
    firstMatrix[0][2] = 3;

    firstMatrix[1][0] = 2;
    firstMatrix[1][1] = 8;
    firstMatrix[1][2] = 1;

    firstMatrix[2][0] = 6;
    firstMatrix[2][1] = 5;
    firstMatrix[2][2] = 7;

    double** secondMatrix = matrixInit(matrixSize);

    secondMatrix[0][0] = 6;
    secondMatrix[0][1] = 9;
    secondMatrix[0][2] = 1;

    secondMatrix[1][0] = 3;
    secondMatrix[1][1] = 6;
    secondMatrix[1][2] = 0;

    secondMatrix[2][0] = 2;
    secondMatrix[2][1] = 4;
    secondMatrix[2][2] = 9;

    double** resultMatrix = matrixAdd(firstMatrix, secondMatrix, matrixSize);

    if (resultMatrix == nullptr) {
        matrixDestroy(firstMatrix, matrixSize);
        matrixDestroy(secondMatrix, matrixSize);

        std::cerr << "Не удалось посчитать матрицу" << std::endl;
        return 0;
    }

//    std::cout << "Result matrix:\n";
//
//    for (int i = 0; i < matrixSize; ++i) {
//        for (int j = 0; j < matrixSize; ++j) {
//            std::cout << resultMatrix[i][j] << ' ';
//        }
//
//        std::cout << '\n';
//    }

//    double x = matrixDeterminant(secondMatrix, 3);
//
//    std::cout << x << std::endl;

    matrixDestroy(firstMatrix, matrixSize);
    matrixDestroy(secondMatrix, matrixSize);
    matrixDestroy(resultMatrix, matrixSize);

    double** testMatrix = matrixInit(4);
    testMatrix[0][0] = 6;
    testMatrix[0][1] = 9;
    testMatrix[0][2] = 1;
    testMatrix[0][3] = 6;

    testMatrix[1][0] = 5;
    testMatrix[1][1] = 6;
    testMatrix[1][2] = 0;
    testMatrix[1][3] = 3;

    testMatrix[2][0] = 2;
    testMatrix[2][1] = 6;
    testMatrix[2][2] = 9;
    testMatrix[2][3] = 8;

    testMatrix[3][0] = 2;
    testMatrix[3][1] = 7;
    testMatrix[3][2] = 8;
    testMatrix[3][3] = 9;

    std::cout << matrixDeterminant(testMatrix, 4) << '\n';

    matrixDestroy(testMatrix, 4);

    return 0;
}
