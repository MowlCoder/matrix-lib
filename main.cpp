#include <iostream>
#include "./include/matrix/matrix.h"

int main() {
    const unsigned int matrixSize = 2;
    double** m = matrixInit(matrixSize);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    matrixDisplay(m, matrixSize);
    std::cout << '\n';

    double** reverseM = matrixReverse(m, matrixSize);
    matrixDisplay(reverseM, matrixSize);
    std::cout << '\n';

    matrixDestroy(m, matrixSize);
    matrixDestroy(reverseM, matrixSize);

    return 0;
}
