#include <iostream>
#include "./include/matrix/matrix.h"

int main() {
    Matrix m = Matrix();
    m.randomizeValues(1, 20);
    m.show();

    return 0;
}
