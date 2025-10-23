#include "FactorialTests.h"

#include "StringInt/StringInt.h"
#include <iostream>


bool DoFactorialTest(int64_t a)
{
    bool passed = true;

    int64_t actual = 1;
    for (int i = 1; i <= a; i++)
        actual *= i;

    StringInt asi(a);
    StringInt csi = !asi;

    if ((int64_t)csi != actual)
    {
        std::cout << "Factorial: " << asi.ToString() << " ! "
            << " = " << csi.ToString()
            << "should be " << actual << std::endl;
        passed = false;
    }
    return passed;
}

bool CheckFactorialTest(int64_t a)
{
    bool passed = DoFactorialTest(a);
    if (passed)
        std::cout << "PASSED: FactorialTest(" << a << ")\n";
    return passed;
}

bool BrithdayTest()
{
    int n = 23;
    StringInt ff = !StringInt(10);

    StringInt numerator = !StringInt(356);
    StringInt denom1 = !StringInt(356 - n);
    StringInt denom2 = StringInt(356) ^ n;
    StringInt denom = denom1 * denom2;

    numerator *= StringInt(100);

    auto result = numerator / denom;
    int r = int64_t(result);
    return r == 48;
}



bool FactorialTests()
{
    bool passed = true;

    passed &= CheckFactorialTest(3);
    passed &= CheckFactorialTest(11);
    passed &= BrithdayTest();

    return passed;
}

