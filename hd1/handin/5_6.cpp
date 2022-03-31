#include "5_6.h"
#include <iostream>
#include <cmath>
#include <cassert>

// print matrix
void printmat(double **matrix, int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        if (i == 0)
        {
            std::cout << "\n|[";
        }
        else
        {
            std::cout << " [";
        }
        for (int j = 0; j < Cols; j++)
        {
            std::cout << matrix[i][j];
            if (j != Cols - 1)
            {
                std::cout << ",";
            }
        }
        if (i == Rows - 1)
        {
            std::cout << "]|\n";
        }
        else
        {
            std::cout << "];\n";
        }
    }
}
// print vec
void printvec(double *vec, int size)
{
    std::cout << "[";
    for (int i = 0; i < size; ++i)
    {
        std::cout << vec[i];
        if (i != size - 1)
        {
            std::cout << ",";
        }
    }
    std::cout << "]\n";
}

// mat x mat
void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols)
{
    // Verify that the matrices are of suitable sizes to be multiplied.
    if (ACols != BRows)
    {
        std::cout << "Size not suitable!";
    }
    else
    {
        for (int i = 0; i < ARows; i++)
        {
            for (int j = 0; j < BCols; j++)
            {
                for (int r = 0; r < BRows; r++)
                {
                    res[i][j] += A[i][r] * B[r][j];
                }
            }
        }
    }
}

// vec x mat
void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols)
{
    if (ACols != BRows)
    {
        std::cout << "Size not suitable!";
    }
    else
    {
        for (int i = 0; i < ACols; i++)
        {
            for (int j = 0; j < BRows; j++)
            {
                res[j] += A[i] * B[i][j];
            }
        }
    }
}
// mat x vec
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows)
{
    if (ACols != BRows)
    {
        std::cout << "Size not suitable!";
    }
    else
    {
        for (int i = 0; i < ARows; i++)
        {
            for (int j = 0; j < BRows; j++)
            {
                res[i] += A[i][j] * B[j];
            }
        }
    }
}
// scalar x met
void Multiply(double **res, double scalar, double **B, int BRows, int BCols)
{
    for (int i = 0; i < BRows; i++)
    {
        for (int j = 0; j < BCols; j++)
        {
            res[i][j] = scalar * B[i][j];
        }
    }
}
// met x scalar
void Multiply(double **res, double **B, double scalar, int BRows, int BCols)
{
    for (int i = 0; i < BRows; i++)
    {
        for (int j = 0; j < BCols; j++)
        {
            res[i][j] = B[i][j] * scalar;
        }
    }
}
