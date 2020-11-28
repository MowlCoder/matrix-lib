#pragma once

#include <iostream>

double** matrixInit(size_t matrixSize);
void matrixDestroy(double** matrix, size_t matrixSize);
void matrixDisplay(double** matrix, size_t matrixSize);
double** matrixAdd(double** firstMatrix, double** secondMatrix, size_t matrixSize);
double** matrixSubtraction(double** firstMatrix, double** secondMatrix, size_t matrixSize);
double** matrixMulti(double** firstMatrix, double** secondMatrix, size_t matrixSize);
double matrixDeterminant(double** matrix, size_t matrixSize);
double** matrixTransposition(double** matrix, size_t matrixSize);
double** matrixReverse(double** matrix, size_t matrixSize);
