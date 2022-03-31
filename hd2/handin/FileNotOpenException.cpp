#include "FileNotOpenException.hpp"
#include <iostream>
#include <fstream>

// Call Exception(tagString, probString)
FileNotOpenException::FileNotOpenException(std::string prob) : Exception("FILE", prob) {}

void ReadFile1(const std::string &filename, double x[], double y[])
{
    std::ifstream readfile(filename.c_str());
    if (readfile.is_open() == false)
    {
        throw FileNotOpenException("File can't be opened");
    }
    for (int i = 0; i < 6; ++i)
    {
        readfile >> x[i] >> y[i];
    }
    readfile.close();
    std::cout << filename << "read successfully\n";
}

// // Copied from book
// int main()
// {
//     double x[6], y[6];
//     try
//     {
//         ReadFile("Output.dat", x, y);
//     }
//     catch (Exception &error)
//     {
//         error.PrintDebug();
//         std::cout << "Couldn't open Output.dat\n";
//         std::cout << "Give alternative location\n";
//         std::string filename;
//         std::cin >> filename;
//         ReadFile(filename, x, y);
//     }
// }