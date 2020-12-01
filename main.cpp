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
    m.show();

    double **at2 = new double*[3];
    at2[0] = new double[3];
    at2[1] = new double[3];
    at2[2] = new double[3];

    at2[0][0] = 6;
    at2[0][1] = 4;
    at2[0][2] = 2;
    at2[1][0] = 7;
    at2[1][1] = 3;
    at2[1][2] = 4;
    at2[2][0] = 0;
    at2[2][1] = 8;
    at2[2][2] = 1;

    Matrix m2 = Matrix(at2, 3);
    m2.show();

    Matrix m3 = m * m2;
    m3.show();

    Matrix m3_reversed = m3.reverse();
    m3_reversed.show();

    return 0;
}
