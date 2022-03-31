#ifndef _CALCULATEEXPONENTIAL_
#define _CALCULATEEXPONENTIAL_

#include "ComplexNumber.hpp"

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res);

ComplexNumber **Allo_Mat(int row, int col);

double fac(int x);

//non mandatory
void printMatrix(ComplexNumber **A, int rows, int cols);

#endif
