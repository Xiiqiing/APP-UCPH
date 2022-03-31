#include "5_3.h"
#include <iostream>

// Swap the values of two double precision floating point numbers
// Write function using pointers
void swap_pointer(double *a, double *b)
{
    double t = *a;
    *a = *b;
    *b = t;
}
// Write function using references
void swap_ref(double &a, double &b)
{
    double t = a;
    a = b;
    b = t;
}