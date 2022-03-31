#include "5_10.h"
#include "5_6.h"
#include <iostream>
#include <cmath>
#include <assert.h>

void guassian_elimination(double **A, double *b, double *u, int n)
{
    // std::cout << " \n";
    // std::cout << "5.10 Input mat: ";
    // printmat(A, n, n);
    // std::cout << "\n";
    // std::cout << "Input vec: ";
    // printvec(b, n);
    // std::cout << "\n";

    // 1. Find max abs
    // Start from A[0][0]
    for (int c = 0; c < n - 1; c++)
    {
        int max_row = c;
        double max_abs = fabs(A[c][c]);
        // compare A[row][col] and A[row + 1][col]
        for (int r = c + 1; r < n; r++)
        {
            if (fabs(A[r][c]) > max_abs)
            {
                max_abs = fabs(A[r][c]);
                max_row = r;
            }
        }
        // singular?
        assert(A[max_row][c] != 0);

        // 2. Interchange rows
        // ---------------- Use Mat P ----------------
        // allocate Mat P
        double **P = new double *[n];
        for (int i = 0; i < n; i++)
        {
            P[i] = new double[n];
        }
        double **tempA = new double *[n];
        for (int i = 0; i < n; i++)
        {
            tempA[i] = new double[n];
        }
        double *tempb = new double[n];
        if (max_row != c)
        {
            // fill Mat P
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    (((i == j) && (i != c) && (j != c) && (i != max_row) && (j != max_row)) || ((i == c) && (j == max_row)) || ((i == max_row) && (j == c))) ? P[i][j] = 1 : P[i][j] = 0;
                }
            }
            // std::cout << "Mat P: ";
            // printmat(P, n, n);
            // std::cout << "\n";
            // P multiply A
            Multiply(tempA, P, A, n, n, n, n);
            // std::cout << "TempMat A: ";
            // printmat(tempA, n, n);
            // std::cout << "\n";
            // P multiply b
            Multiply(tempb, P, b, n, n, n);
            // std::cout << "TempVec B: ";
            // printvec(tempb, n);

            for (int i = 0; i < n; i++)
            {
                b[i] = tempb[i];
                tempb[i] = 0.;
                for (int j = 0; j < n; j++)
                {
                    A[i][j] = tempA[i][j];
                    tempA[i][j] = 0.;
                }
            }
            // std::cout << "Interchanged Mat A: ";
            // printmat(A, n, n);
            // std::cout << "\n";
            // std::cout << "And Vec b: ";
            // printvec(b, n);
            // std::cout << "\n";
        }

        for (int i = 0; i < n; i++)
        {
            delete[] P[i];
        }
        delete[] P;
        for (int i = 0; i < n; i++)
        {
            delete[] tempA[i];
        }
        delete[] tempA;
        delete[] tempb;

        // 3. Elimination
        double factor;
        for (int i = c + 1; i < n; i++)
        {
            factor = A[i][c] / A[c][c];
            b[i] -= factor * b[c];
            for (int j = 0; j < n; j++)
            {
                A[i][j] -= factor * A[c][j];
            }
            // std::cout << "Eliminated Mat: ";
            // printmat(A, n, n);
            // std::cout << "\n";
            // std::cout << "Eliminated Vec: ";
            // printvec(b, n);
            // std::cout << "\n";
        }
    }

    // 4. Back substitution
    // The last one in vec u
    u[n - 1] = b[n - 1] / A[n - 1][n - 1];
    // Other elements in vec u
    for (int i = n - 2; i >= 0; i--)
    {
        double sum = 0.;
        for (int j = i + 1; j < n; j++)
        {
            sum += A[i][j] * u[j];
            u[i] = (b[i] - sum) / A[i][i];
        }
    }
}

// ---------------- Another way to interchange rows ----------------
// if (max_row != c)
// {
//     // interchange rows in A
//     double temp1;
//     for (int i = 0; i < n; i++)
//     {
//         temp1 = A[max_row][i];
//         A[max_row][i] = A[c][i];
//         A[c][i] = temp1;
//     }
//     std::cout << "Interchangeed mat: ";
//     printmat(A, n, n);
//     std::cout << "\n";
//
//     // interchange b
//     double temp2 = b[max_row];
//     b[max_row] = b[c];
//     b[c] = temp2;
//     std::cout << "InterchangeD vec: ";
//     printvec(b, n);
//     std::cout << "\n";
// }