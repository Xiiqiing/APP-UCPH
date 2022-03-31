#include "5_9.h"
#include <iostream>
#include <cmath>
#include <assert.h>

void solve3by3(double **A, double *b, double *u)
{
    // determinant
    double mat_det = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) - A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) + A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
    std::cout << "5.9 Determinant = " << mat_det << "\n";
    assert(mat_det != 0);

    // adjoint matrix
    double mat_adj[3][3] = {A[1][1] * A[2][2] - A[1][2] * A[2][1], A[0][2] * A[2][1] - A[0][1] * A[2][2], A[0][1] * A[1][2] - A[0][2] * A[1][1], A[1][2] * A[2][0] - A[1][0] * A[2][2], A[0][0] * A[2][2] - A[0][2] * A[2][0], A[0][2] * A[1][0] - A[0][0] * A[1][2], A[1][0] * A[2][1] - A[1][1] * A[2][0], A[0][1] * A[2][0] - A[0][0] * A[2][1], A[0][0] * A[1][1] - A[0][1] * A[1][0]};

    // inverse matrix
    double mat_inv[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat_inv[i][j] = mat_adj[i][j] / mat_det;
        }
    }
    
    //u = A^-1 * B
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            u[i] += mat_inv[i][j] * b[j];
        }
    }
}

