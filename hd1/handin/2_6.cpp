#include "2_6.h"
#include <cmath>
#include <iostream>

double fun(double x)
{
    return exp(x) + pow(x, 3) - 5;
}
double fun_d(double x)
{
    return exp(x) + 3 * pow(x, 2);
}

// for-loop
// double newton_Raphson(double initialGuess, double epsilon)
// {
//     double x_p = initialGuess, double x_n = x_p - fun(x_p) / fun_d(x_p), diff;
//     for (int i = 0; i < 100; i++)
//     {
//         x_p = x_n;
//         x_n = x_p - fun(x_p) / fun_d(x_p);
//         //std::cout << (x_n) <<  "\n";
//         diff = fabs(x_n - x_p);
//         if (diff < epsilon)
//         {
//             std::cout << "Iteration terminates, different: " << (diff) << "\n";
//             break;
//         }
//     }
//     return x_n;
// }

double newton_Raphson(double initialGuess, double epsilon)
{
    double x_p = initialGuess, x_n = x_p - fun(x_p) / fun_d(x_p), diff;
    do
    {
        x_p = x_n;
        x_n = x_p - fun(x_p) / fun_d(x_p);
        diff = fabs(x_n - x_p);
    } while (diff > epsilon);
    //std::cout << "Iteration terminates, different: " << diff << "\n";
    //std::cout << "\n";
    return x_n;
}