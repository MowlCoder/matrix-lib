#include <iostream>
#include "./include/matrix/matrix.h"

int main() {
    const unsigned int matrixSize = 3;
    double** m = matrixInit(matrixSize);
    m[0][0] = 2;
    m[0][1] = 5;
    m[0][2] = 7;
    m[1][0] = 6;
    m[1][1] = 3;
    m[1][2] = 4;
    m[2][0] = 5;
    m[2][1] = -2;
    m[2][2] = -3;

    matrixDisplay(m, matrixSize);
    std::cout << '\n';

    double** reverseM = matrixReverse(m, matrixSize);
    matrixDisplay(reverseM, matrixSize);
    std::cout << '\n';

    matrixDestroy(m, matrixSize);
    matrixDestroy(reverseM, matrixSize);

    return 0;
}
