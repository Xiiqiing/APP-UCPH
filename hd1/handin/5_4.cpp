#include "5_4.h"
#include <iostream>
#include <cmath>

double calc_mean(double a[], int length)
{
    double mean, sum;
    for (int i = 0; i < length; i++)
    {
        sum += a[i];
    }
    return mean = sum / length;
}

double calc_std(double a[], int length)
{
    double mean = calc_mean(a, length), std, sum;
    for (int i = 0; i < length; i++)
    {
        sum += pow(a[i] - mean, 2);
    }
    // Do not divide by zero when calculating the standard deviation when the length is 1
    if (length <= 1)
    {
        std::cout << "Length must greater than 1!"
                  << "\n";
    }
    else
    {
        return std = sqrt(sum / (length - 1));
    }
    return 0;
}