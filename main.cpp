#include <iostream>
#include "./include/matrix/matrix.h"

int main() {
    double **at = new double*[3];
    at[0] = new double[3];
    at[1] = new double[3];
    at[2] = new double[3];

    at[0][0] = 2;
    at[0][1] = 6;
    at[0][2] = 3;
    at[1][0] = 7;
    at[1][1] = 9;
    at[1][2] = 4;
    at[2][0] = 2;
    at[2][1] = 9;
    at[2][2] = 1;

    Matrix m = Matrix(at, 3);

    double **at2 = new double*[3];
    at2[0] = new double[3];
    at2[1] = new double[3];
    at2[2] = new double[3];

    at2[0][0] = 6;
    at2[0][1] = 2;
    at2[0][2] = 3;
    at2[1][0] = 2;
    at2[1][1] = 9;
    at2[1][2] = 5;
    at2[2][0] = 1;
    at2[2][1] = 9;
    at2[2][2] = 0;

    Matrix m2 = Matrix(at2, 3);

    Matrix m3 = m + m2;

    m3.show();

    m3.valueAdd(10);
    m3.valueSubtract(3);
    m3.valueMultiply(2);

    m3.show();

    std::cout << m3.toDebugString() << '\n';

    delete at[0];
    delete at[1];
    delete at[2];

    delete at2[0];
    delete at2[1];
    delete at2[2];

    delete[] at;
    delete[] at2;

    return 0;
}
