#include "GraduateStudent.hpp"

// Call base class Student
GraduateStudent::GraduateStudent() : Student(){}

// Call Student(name, fines, fees) and add fullTime
GraduateStudent::GraduateStudent(std::string name, double fines, double fees, bool fullTime):Student(name, fines, fees)
{
    fullTime = fullTime;
}

// No tuition fees
double GraduateStudent::MoneyOwed() const
{
    return GetLibraryFines();
}
