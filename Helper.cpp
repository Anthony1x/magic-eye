#include "Helper.h"

Color Helper::RandomColor(const bool noAlpha = false)
{
    const unsigned char r = static_cast<unsigned char>(GetRandomValue(0, 255));
    const unsigned char g = static_cast<unsigned char>(GetRandomValue(0, 255));
    const unsigned char b = static_cast<unsigned char>(GetRandomValue(0, 255));
    const unsigned char a = static_cast<unsigned char>(GetRandomValue(0, 255));

    if (noAlpha == true)
        return (Color){r, g, b, 255};
    else
        return (Color){r, g, b, a};
}

/*
 * This function takes two integers as input (a and b)
 * and returns a vector containing all the common divisors between them.
 */
std::vector<int> Helper::CommonDivisors(int a, int b)
{
    std::vector<int> divisors;
    // Use std::gcd to find the greatest common divisor
    int gcd = std::gcd(a, b);

    // Iterate from 1 to gcd and check for divisors
    for (int i = 1; i <= gcd; ++i)
    {
        if (gcd % i == 0 && (a % i == 0 || b % i == 0))
        {
            divisors.push_back(i);
        }
    }
    return divisors;
}
