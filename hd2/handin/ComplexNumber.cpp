#include "ComplexNumber.hpp"
#include <cmath>
#include <iostream>

// From Book
// Override default constructor
// Set real and imaginary parts to zero
ComplexNumber::ComplexNumber()
{
    mRealPart = 0.0;
    mImaginaryPart = 0.0;
}

// Constructor that sets complex number z=x+iy
ComplexNumber::ComplexNumber(double x, double y)
{
    mRealPart = x;
    mImaginaryPart = y;
}

// Method for computing the modulus of a
// complex number
double ComplexNumber::CalculateModulus() const
{
    return sqrt(mRealPart * mRealPart +
                mImaginaryPart * mImaginaryPart);
}

// Method for computing the argument of a
// complex number
double ComplexNumber::CalculateArgument() const
{
    return atan2(mImaginaryPart, mRealPart);
}

// Method for raising complex number to the power n
// using De Moivre's theorem - first complex
// number must be converted to polar form
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
    double modulus = CalculateModulus();
    double argument = CalculateArgument();
    double mod_of_result = pow(modulus, n);
    double arg_of_result = argument * n;
    double real_part = mod_of_result * cos(arg_of_result);
    double imag_part = mod_of_result * sin(arg_of_result);
    ComplexNumber z(real_part, imag_part);
    return z;
}

// Overloading the = (assignment) operator
ComplexNumber &ComplexNumber::operator=(const ComplexNumber &z)
{
    mRealPart = z.mRealPart;
    mImaginaryPart = z.mImaginaryPart;
    return *this;
}

// Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const
{
    ComplexNumber w;
    w.mRealPart = -mRealPart;
    w.mImaginaryPart = -mImaginaryPart;
    return w;
}

// Overloading the binary + operator
ComplexNumber ComplexNumber::operator+(const ComplexNumber &z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart + z.mRealPart;
    w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
    return w;
}

// Overloading the binary - operator
ComplexNumber ComplexNumber::operator-(const ComplexNumber &z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart - z.mRealPart;
    w.mImaginaryPart = mImaginaryPart - z.mImaginaryPart;
    return w;
}

// Overloading the insertion << operator
std::ostream &operator<<(std::ostream &output, const ComplexNumber &z)
{
    // Format as "(a + bi)" or as "(a - bi)"
    output << "(" << z.mRealPart << " ";
    if (z.mImaginaryPart >= 0.0)
    {
        output << "+ " << z.mImaginaryPart << "i)";
    }
    else
    {
        // z.mImaginaryPart < 0.0
        // Replace + with minus sign
        output << "- " << -z.mImaginaryPart << "i)";
    }
    return output;
}

// For exercise 6.1.7, Overloading the * and / (only for int) operator
ComplexNumber ComplexNumber::operator*(const ComplexNumber &z) const
{
    ComplexNumber w;
    // (ac-bd)
    w.mRealPart = mRealPart * z.mRealPart- mImaginaryPart * z.mImaginaryPart;
    // (bc+ad)i
    w.mImaginaryPart = mImaginaryPart * z.mRealPart + mRealPart * z.mImaginaryPart;
    return w;
}
ComplexNumber ComplexNumber::operator/(const double &z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart / z;
    w.mImaginaryPart = mImaginaryPart / z;
    return w;
}
// // reset tempmat
// void ComplexNumber::Reset()
// {
//     mRealPart = 0.0;
//     mImaginaryPart = 0.0;
// }


// Exercise
// 6.1.1 Access private members
double ComplexNumber::GetRealPart() const
{
    return mRealPart;
}
double ComplexNumber::GetImaginaryPart() const
{
    return mImaginaryPart;
}
// 6.1.2 Access by friend
double RealPart(const ComplexNumber &z)
{
    return z.mRealPart;
}
double ImaginaryPart(const ComplexNumber &z)
{
    return z.mImaginaryPart;
}
// 6.1.3 An overridden copy constructor
ComplexNumber::ComplexNumber(const ComplexNumber &z)
{
    mRealPart = z.GetRealPart();
    mImaginaryPart = z.GetImaginaryPart();
}
// 6.1.4 
ComplexNumber::ComplexNumber(double real)
{
    mRealPart = real;
    mImaginaryPart = 0.;
}
// 6.1.5 Return conjugate
ComplexNumber ComplexNumber::CalculateConjugate() const
{
    double imag_part = -mImaginaryPart;
    ComplexNumber z(mRealPart, imag_part);
    return z;
}
//6.1.6
void ComplexNumber::SetConjugate()
{
    mImaginaryPart = -mImaginaryPart;
}