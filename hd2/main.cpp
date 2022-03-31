#include <iostream>
// #include <sstream>
// #include <ctime>
// #include <random>

#include "./handin/ComplexNumber.hpp"
#include "./handin/CalculateExponential.hpp"
// #include "./handin/Exception.hpp"
// #include "./handin/Exercise82.hpp"
// #include "./handin/FileNotOpenException.hpp"
// #include "./handin/GraduateStudent.hpp"
//#include "./handin/Matrix2x2.hpp"
// #include "./handin/OutOfRangeException.hpp"
// #include "./handin/PhdStudent.hpp"
// #include "./handin/Student.hpp"

int main()
{
  // 6.1.1

  //---------------------------------------------------------------

  // 6.1.2

  // ........

  //6.1.7
  ComplexNumber **test6_17 = Allo_Mat(3, 3);
  ComplexNumber **test6_17_res = Allo_Mat(3, 3);
  ComplexNumber test1(2, 3), test2(4, 5), test3(6, 7);
  test6_17[0][0] = test1;
  test6_17[1][1] = test2;
  test6_17[2][2] = test3;
  CalculateExponential(test6_17, 50, test6_17_res);
  printMatrix(test6_17_res, 3, 3);
  for (int i = 0; i < 3; i++)
  {
    delete[] test6_17[i];
  }
  delete[] test6_17;
  for (int i = 0; i < 3; i++)
  {
    delete[] test6_17_res[i];
  }
  delete[] test6_17_res;

  // // 6.2.5
  // Matrix2x2 test6_25(1, 2, 3, 4.3);
  // Matrix2x2 res6_25(test6_25.CalcInverse());
  // std::cout << res6_25.Getval00() << " " << res6_25.Getval01() << "\n";
  // std::cout << res6_25.Getval10() << " " << res6_25.Getval11() << "\n";

  do
  {
    std::cout << '\n'
              << "Press the Enter key to continue.";
  } while (std::cin.get() != '\n');

  return 0;
}