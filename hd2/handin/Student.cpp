#include "Student.hpp"
#include <iostream>
#include <string>
#include <cmath>

Student::Student()
{
    tuition_fees = 0.;
    library_fines = 0.;
    name = "unspecified";
}
Student::Student(std::string myname, double fines, double fees)
{
    name = myname;
    tuition_fees = fees;
    SetLibraryFines(fines);
}
// Method that returns the total money owed by the student (library fines + tuition fees)
double Student::MoneyOwed() const
{
    return GetLibraryFines() + tuition_fees;
}
// Fine must be nonnegative values,
void Student::SetLibraryFines(double amount)
{
    if (amount >=0)
    {
        library_fines = amount;
    }
    else
    {
        std::cout << "Invalid library fines, maybe you mean" << -amount << "?\n";
        library_fines = -amount;
    }
}
// Method that can be used to access this private variable.
double Student::GetLibraryFines() const
{
    return library_fines;
}
