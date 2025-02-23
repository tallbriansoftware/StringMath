#include "FactorialTests.h"

#include "StringInt/StringInt.h"
#include <iostream>

bool DoFactorialTest(int64_t a)
{
    bool passed = true;

    int64_t c = 1;
    for (int i = 1; i <= a; i++)
    {
        c *= i;
    }

    StringInt asi(a);
    StringInt csi = !asi;

    if ((long long)csi != c)
    {
        std::cout << "Factorial: " << asi.ToString() << " ! " << " = " << csi.ToString()
            << "should be " << c << std::endl;
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



bool FactorialTests()
{
    bool passed = true;

    passed &= CheckFactorialTest(3);
    passed &= CheckFactorialTest(11);

    return passed;
}