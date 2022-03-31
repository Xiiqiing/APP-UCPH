#include <iostream>

#include "./handin/2_6.h"
#include "./handin/3_3.h"
#include "./handin/5_3.h"
#include "./handin/5_4.h"
#include "./handin/5_6.h"
#include "./handin/5_9.h"
#include "./handin/5_10.h"

int main()
{
    // 2.6 double newton_Raphson(double initialGuess, double epsilon);
    double newton = newton_Raphson(0, 0.0001);
    std::cout << "2.6 Solution: " << newton << "\n";
    std::cout << "\n";
    //---------------------------------------------------------------

    // 3.3
    std::cout << "3.3 Euler, output results in xy.dat\n";
    implicit_Euler(10);
    std::cout << "\n";
    //---------------------------------------------------------------

    // 5.3
    std::cout << "5.3 Swap the values of two double precision floating point numbers:\n";
    double a = 1.0, b = 2.0;
    std::cout << a << " " << b << "\n";
    swap_pointer(&a, &b);
    std::cout << a << " " << b << "\n";
    swap_ref(a, b);
    std::cout << a << " " << b << "\n";
    std::cout << "\n";
    //---------------------------------------------------------------

    // 5.4
    int n = 4;
    double *array = new double[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = i * 0.9;
    }
    std::cout << "5.4 The mean is: " << calc_mean(array, n) << "\n";
    std::cout << "5.4 The standard dev is: " << calc_std(array, n) << "\n";
    std::cout << "\n";
    delete[] array;
    //---------------------------------------------------------------

    // 5.6
    int ARows = 5, BRows = 5, ACols = 5, BCols = 5;
    // mat1
    double **A = new double *[ARows];
    for (int i = 0; i < ARows; i++)
    {
        A[i] = new double[ACols];
    }
    double mat[5][5] = {{1, 2, 3, 4, 5}, {1, 2, 2, 3, 3}, {1, 2, 3, 4, 5}, {3, 4, 6, 5, 7}, {1, 2, 3, 10, 5}};
    for (int i = 0; i < ARows; i++)
    {
        for (int j = 0; j < ACols; j++)
        {
            A[i][j] = mat[i][j];
        }
    }
    //mat2
    double **B = new double *[BRows];
    for (int i = 0; i < BRows; i++)
    {
        B[i] = new double[BCols];
    }
    for (int i = 0; i < BRows; i++)
    {
        for (int j = 0; j < BCols; j++)
        {
            B[i][j] = i * j;
        }
    }
    //**res
    double **res = new double *[BRows];
    for (int i = 0; i < BRows; i++)
    {
        res[i] = new double[BCols];
    }
    //*res
    double *res2 = new double[ACols];
    // vector
    double *V = new double[ARows];
    for (int i = 0; i < ARows; i++)
    {
        V[i] = i;
    }
    // scalar
    double scalar = 5;

    // print
    std::cout << "5.6 Input mat\n";
    printmat(A, ARows, ACols);
    std::cout << "\n";
    printmat(B, BRows, BCols);
    std::cout << "\n";
    std::cout << "Input vec: ";
    printvec(V, ARows);
    std::cout << "\n";
    //mat x mat
    Multiply(res, A, B, ARows, ACols, BRows, BCols);
    std::cout << "mat x mat:";
    printmat(res, ARows, BCols);
    std::cout << "\n";
    //vec x mat
    Multiply(res2, V, A, ACols, BRows, BCols);
    std::cout << "vec x mat:";
    printvec(res2, ACols);
    std::cout << "\n";
    // mat x vec
    Multiply(res2, A, V, ARows, ACols, BRows);
    std::cout << "mat x vec:";
    printvec(res2, ARows);
    std::cout << "\n";

    // // scalar x met
    Multiply(res, scalar, A, BRows, BCols);
    std::cout << "scalar x met:";
    printmat(res, BRows, BCols);
    std::cout << "\n";
    // met x scalar
    Multiply(res, A, scalar, BRows, BCols);
    std::cout << "met x scalar:";
    printmat(res, BRows, BCols);
    std::cout << "\n";
    for (int i = 0; i < ARows; i++)
    {
        delete[] A[i];
    }
    delete[] A;
    for (int i = 0; i < BRows; i++)
    {
        delete[] B[i];
    }
    delete[] B;
    for (int i = 0; i < BRows; i++)
    {
        delete[] res[i];
    }
    delete[] res;
    delete[] res2;
    delete[] V;
    //---------------------------------------------------------------
    // 5.9 Solve 3X3 Ax=Y
    double **D = new double *[3];
    for (int i = 0; i < 3; i++)
    {
        D[i] = new double[3];
    }
    double mat2[3][3] = {{2, 1, 1}, {6, 2, 1}, {-2, 2, 1}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            D[i][j] = mat2[i][j];
        }
    }
    printmat(D, 3,3);
    double *y = new double[3];
    y[0] = 1;
    y[1] = -1;
    y[2] = 7;
    // for (int i = 0; i < 3; i++)
    // {
    //     y[i] = i + 1;
    // }
    double *u = new double[3];
    solve3by3(D, y, u);
    std::cout << "5.9 u= ";
    printvec(u, 3);
    std::cout << "\n";
    //---------------------------------------------------------------
    // 5.10 Gaussian elimination with pivoting
    guassian_elimination(D, y, u, 3);
    std::cout << "5.10 u= ";
    printvec(u, 3);
    std::cout << "\n";
    //delete
    for (int i = 0; i < 3; i++)
    {
        delete[] D[i];
    }
    delete[] D;
    delete[] y;
    delete[] u;

    //--------------------------------------------------------------------
    do
    {
        std::cout << '\n'
                  << "Press the Enter key to continue.";
    } while (std::cin.get() != '\n');

    return 0;
}