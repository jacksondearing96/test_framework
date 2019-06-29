#include <iostream>

// Declare colour strings for console output
std::string colourReset="\x1b[0m";
std::string green="\x1b[42m";
std::string red="\033[0;31m";

template <class T>
void COMPARE(T actual, T expected, std::string description)
{
    if (actual == expected)
    {
        std::cout << green << "PASS" << colourReset << " -> " << description << std::endl;
    }
    else
    {
        std::cout << red << "FAIL" << colourReset << std::endl;
        std::cout << "\tFailed test: " << description << std::endl;
        std::cout << "\tExpected: " << expected << std::endl;
        std::cout << "\tActual: " << actual << std::endl;
    }
}