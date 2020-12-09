#include <iostream>
#include "./include/matrix/matrix.h"
#include "./include/random/random.h"

int main() {
    double **at = new double*[MATRIX_DEFAULT_SIZE];

    for (byte i = 0; i < MATRIX_DEFAULT_SIZE; i++) {
        at[i] = new double[MATRIX_DEFAULT_SIZE];
        for (byte j = 0; j < MATRIX_DEFAULT_SIZE; j++) {
            at[i][j] = getRandomNumber();
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
