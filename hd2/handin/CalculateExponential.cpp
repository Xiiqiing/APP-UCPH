#include "CalculateExponential.hpp"
#include "ComplexNumber.hpp"
#include <iostream>
#include <cmath>

void printMatrix(ComplexNumber **A, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        if (i == 0)
        {
            std::cout << "\n|[";
        }
        else
        {
            std::cout << " [";
        }
        for (int j = 0; j < cols; j++)
        {
            std::cout << A[i][j];
            if (j != cols - 1)
            {
                std::cout << ",";
            }
        }
        if (i == rows - 1)
        {
            std::cout << "]|\n";
        }
        else
        {
            std::cout << "];\n";
        }
    }
}


// Factorial
double fac(int x)
{
    double factorial;
    (x == 0 || x == 1) ? factorial = 1 : factorial = fac(x - 1) * x;
    return factorial;
}

ComplexNumber **Allo_Mat(int row, int col)
{
    ComplexNumber **mat = new ComplexNumber *[row];
    for (int i = 0; i < row; i++)
    {
        mat[i] = new ComplexNumber[col];
    }
    return mat;
}

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res)
{
    int size = 3;
    ComplexNumber **tempow = Allo_Mat(size, size);
    ComplexNumber **Apow = Allo_Mat(size, size);
    // std::cout << "Mat A:\n";
    // printMatrix(A, 3, 3);
    // Fill identity mat
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            i == j ? res[i][j] = 1. : res[i][j] = 0.;
        }
    }
    // std::cout << "Identity mat:\n";
    // printMatrix(res, 3, 3);
    // Apow = A
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            Apow[i][j] = A[i][j];
        }
    }
    // I + A (n = 0 and 1)
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            res[i][j] = res[i][j] + A[i][j];
        }
    }
    // std::cout << "I + A:\n";
    // printMatrix(res, 3, 3);
    // When n > 2
    for (int n = 2; n <= nMax; n++)
    {
        // Mat A^n
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                tempow[i][j] = 0;
                for (int r = 0; r < size; r++)
                {
                    tempow[i][j] = tempow[i][j] + A[i][r] * Apow[r][j];
                }
            }
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                Apow[i][j] = tempow[i][j];
            }
        }
        // std::cout << "A^" << n << ":\n";
        // printMatrix(Apow, 3, 3);
        // Sum all
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                res[i][j] = res[i][j] + Apow[i][j] / fac(n);
            }
        }
        // std::cout << "Factorial n^"<< n <<":" << fac(n) << "\n ";
        // std::cout << n << "times:\n";
        // printMatrix(res, 3, 3);
    }
    // delete
    for (int i = 0; i < size; i++)
    {
        delete[] tempow[i];
    }
    delete[] tempow;
    for (int i = 0; i < size; i++)
    {
        delete[] Apow[i];
    }
    delete[] Apow;
}
