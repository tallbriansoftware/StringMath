#include "MultTests.h"

#include "StringInt/StringInt.h"
#include <iostream>


bool DoMultTest(int64_t a, int64_t b)
{
    int64_t c = a * b;

    StringInt asi(a);
    StringInt bsi(b);
    StringInt csi = asi * bsi;

    StringInt dsi = asi;
    dsi *= bsi;

    bool passed = true;

    if ((long long)csi != c)
    {
        std::cout << "* FAIL: " << asi.ToString() << " * " << bsi.ToString() << " = " << csi.ToString()
            << " should be " << c << std::endl;
        passed = false;
    }

    int64_t d = (long long)dsi;

    if ((long long)dsi != c)
    {
        std::cout << "*= FAIL: " << asi.ToString() << " *= " << bsi.ToString() << " makes " << dsi.ToString()
            << "should be " << c << std::endl;
        passed = false;
    }
    return passed;
}

bool CheckAllMultTest(int64_t a, int64_t b)
{
    bool passed = true;

    passed &= DoMultTest(a, b);
    passed &= DoMultTest(a, -b);
    passed &= DoMultTest(-a, b);
    passed &= DoMultTest(-a, -b);

    return passed;
}


bool CheckMultTest(int64_t a, int64_t b)
{
    bool passed = CheckAllMultTest(a, b);
    if (passed)
        std::cout << "PASSED: MultTest(" << a << ", " << b << ")\n";
    return passed;
}


bool MultTests()
{
    bool passed = true;

    passed &= CheckMultTest(4, 5);
    passed &= CheckMultTest(0, 555);
    passed &= CheckMultTest(0, 0);
    passed &= CheckMultTest(101, 77);
    passed &= CheckMultTest(7364, 339256);
    passed &= CheckMultTest(111155111, 66234);

    return passed;
}