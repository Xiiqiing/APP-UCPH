#include "3_3.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include <fstream>

void implicit_Euler(int n)
{
    // Use an assert to ensure that n is greater than 1
    assert(n > 1);
    // Use n to calculate constant step size
    double const h = 1. / n;
    std::ofstream write_output("xy.dat");
    assert(write_output.is_open());
    // (y_n - y_p)/h = -y_n -> y_n/h + y_n = y_p/h ->
    // y_n * (h + 1) = y_p -> y_n = y_p / (h + 1)
    double y_p = 1., y_i = 1.;
    for (int i = 0; i < n; i++)
    {
        write_output << (i * h) << "," << y_i << "\n";
        y_i = y_p / (h + 1.);
        y_p = y_i;
    }
    write_output.close();
}
