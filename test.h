#ifndef TESTING_FRAMEWORK_H
#define TESTING_FRAMEWORK_H

#include <iostream>
#include <vector>

class Test
{
public:
    // Declare colour strings for console output.
    static const std::string COLOUR_RESET;
    static const std::string GREEN;
    static const std::string RED;

    template <class T>
    static void EXPECT_EQ(const T& actual, const T& expected, const std::string& description)
    {
        if (actual == expected)
        {
            std::cout << GREEN << "PASS" << COLOUR_RESET << " -> " << description << std::endl;
        }
        else
        {
            std::cout << RED << "FAIL" << COLOUR_RESET << std::endl;
            std::cout << "\tFailed test: " << description << std::endl;
            std::cout << "\tExpected: " << expected << std::endl;
            std::cout << "\tActual: " << actual << std::endl;
        }
    }

    // TODO: Would be nice to implement the test framework like this.
    // Avoids having to write a test and then explicitly call it from main()
    static void RunAllTests()
    {
        for (auto testFunction : testFunctions) testFunction();
    }
    static std::vector<void(*)()> testFunctions;
};
#endif // TESTING_FRAMEWORK_H

const std::string Test::COLOUR_RESET =  "\x1b[0m";
const std::string Test::GREEN = "\x1b[42m";
const std::string Test::RED = "\033[0;31m";