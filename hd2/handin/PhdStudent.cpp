#include "PhdStudent.hpp"

// Call GraduateStudent
PhdStudent::PhdStudent(std::string name, double fines, double fees, bool fullTime):GraduateStudent(name, fines, fees, fullTime){}

// Nothing owned by Phd
double PhdStudent::MoneyOwed() const
{
    return 0;
}