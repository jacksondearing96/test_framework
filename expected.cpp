#include <iostream>
#include <cmath>
#include <string>

const int ToBase10(const std::string number, const int base)
{
    int base10Equivalent = 0;
    int power, digit;
    for (int i = 0; i < number.length(); i++)
    {
        power = number.length() - 1 - i;
        digit = static_cast<int>(number[i]) - '0';
        base10Equivalent += digit * pow(base, power);
    }
    return base10Equivalent;
}

void PrintInBase(int number, int base)
{
   if (number < base)
   {
      std::cout << number;
      return;
   }

   int rem = number % base;
   PrintInBase(number / base, base);
   std::cout << rem;
}

int main()
{
    std::string int1, int2;
    int base;

    std::cin >> int1;
    std::cin >> int2;
    std::cin >> base;

    const int int1Base10 = ToBase10(int1, base);
    const int int2Base10 = ToBase10(int2, base);

    int sum      = int1Base10 + int2Base10;
    int product  = int1Base10 * int2Base10;
    int quotient = 0;// int1Base10 / int2Base10;

    PrintInBase(sum, base);
    std::cout << " ";
    PrintInBase(product, base);
    std::cout << " ";
    PrintInBase(quotient, base);

    return 0;
}