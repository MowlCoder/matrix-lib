#include <iostream>
#include <random>
#include <ctime>
#include "./include/matrix/matrix.h"

int main() {
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::uniform_int_distribution die{ 1, 20 };

    double **at = new double*[MATRIX_DEFAULT_SIZE];

    for (byte i = 0; i < MATRIX_DEFAULT_SIZE; i++) {
        at[i] = new double[MATRIX_DEFAULT_SIZE];
        for (byte j = 0; j < MATRIX_DEFAULT_SIZE; j++) {
            at[i][j] = die(mersenne);
        }
    }

    Matrix m = Matrix(at, 3);

    m.show();

    for (byte i = 0; i < MATRIX_DEFAULT_SIZE; i++) {
        delete[] at[i];
    }

    delete[] at;

    return 0;
}
