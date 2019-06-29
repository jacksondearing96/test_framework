#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>

#include <sys/time.h>

long GetMicroTime()
{
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

const std::string RandomNumber(const size_t length, const int base)
{
    int digit;
    std::string number = "";
    for (int i = 0; i < length; i++)
    {
        do 
        {
            digit = rand() % base;
        }
        while ((i == 0) && (digit == 0));
        
        number += std::to_string(digit);
    }
    return number;
}

int main(int argc, char* argv[])
{
    srand(GetMicroTime());
    
    const size_t length1 = rand() % 6 + 1;
    const size_t length2 = rand() % 6 + 1;
    const int    base    = rand() % 9 + 2;

    const std::string int1 = RandomNumber(length1, base);
    const std::string int2 = RandomNumber(length2, base);

    std::cout << int1 << " " << int2 << " " << base;
    return 0;
}