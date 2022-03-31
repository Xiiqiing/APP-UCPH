#include "Matrix2x2.hpp"
#include <iostream>
#include <cmath>

// 6.2
// An overridden default constructor that initialises all entries of the matrix to zero.
Matrix2x2::Matrix2x2()
{
    val00 = 0.;
    val01 = 0.;
    val10 = 0.;
    val11 = 0.;
}

// An overridden copy constructor.
Matrix2x2::Matrix2x2(const Matrix2x2 &other)
{
    val00 = other.Getval00();
    val01 = other.Getval01();
    val10 = other.Getval10();
    val11 = other.Getval11();
}

// A constructor that specifies the four entries of the matrix and allocates these entries appropriately.
Matrix2x2::Matrix2x2(double a, double b, double c, double d)
{
    val00 = a;
    val01 = b;
    val10 = c;
    val11 = d;
}

// A method (function) that returns the determinant of the matrix.
double Matrix2x2::CalcDeterminant() const
{
    return (val00 * val11) - (val01 * val10);
}

// A method that returns the inverse of the matrix, if it exists.
Matrix2x2 Matrix2x2::CalcInverse() const
{
    Matrix2x2 inv;
    double det = CalcDeterminant();
    if (det != 0)
    {
        inv = Matrix2x2(Getval11() / det, Getval01() / det, Getval10() / det, Getval00() / det);
    }
    else
    {
        std::cout << "Determinant cannot be 0.";
    }
    return inv;
}

// Overloading of the assignment operator: A = B
Matrix2x2 &Matrix2x2::operator=(const Matrix2x2 &z)
{
    val00 = z.val00;
    val01 = z.val01;
    val10 = z.val10;
    val11 = z.val11;
    return *this;
}

// Overloading of the unary subtraction operator: A = -B
Matrix2x2 Matrix2x2::operator-() const
{
    Matrix2x2 z;
    z.val00 = -val00;
    z.val01 = -val01;
    z.val10 = -val10;
    z.val11 = -val11;
    return z;
}

// Overloading of the binary addition and subtraction operators: A = B + C and A = B - C
Matrix2x2 Matrix2x2::operator+(const Matrix2x2 &z) const
{
    Matrix2x2 w;
    w.val00 = val00 + z.val00;
    w.val01 = val01 + z.val01;
    w.val10 = val10 + z.val10;
    w.val11 = val11 + z.val11;
    return w;
}
Matrix2x2 Matrix2x2::operator-(const Matrix2x2 &z) const
{
    Matrix2x2 w;
    w.val00 = val00 - z.val00;
    w.val01 = val01 - z.val01;
    w.val10 = val10 - z.val10;
    w.val11 = val11 - z.val11;
    return w;
}

// A method that multiplies a matrix by a specified double precision floating point variable
void Matrix2x2::MultScalar(double scalar)
{
    val00 = val00 * scalar;
    val01 = val01 * scalar;
    val10 = val10 * scalar;
    val11 = val11 * scalar;
}