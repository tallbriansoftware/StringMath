#include "DivisionTests.h"
#include "StringInt/StringInt.h"
#include <iostream>

bool DoDivTest(int64_t a, int64_t b)
{
    int64_t c = a / b;

    StringInt asi(a);
    StringInt bsi(b);
    StringInt csi = asi / bsi;

    StringInt dsi = asi;
    dsi /= bsi;

    bool passed = true;

    if ((int64_t)csi != c)
    {
        std::cout << "/ FAIL: " << asi.ToString() << " / " << bsi.ToString() << " = (" << csi.ToString() << ")"
            << " should be " << c << std::endl;

        passed = false;
    }

    if ((int64_t)dsi != c)
    {
        std::cout << "*= FAIL: " << asi.ToString() << " *= " << bsi.ToString() << " makes " << dsi.ToString()
            << " should be " << c << std::endl;
        passed = false;
    }
    return passed;
}

bool CheckAllDivTest(int64_t a, int64_t b)
{
    bool passed = true;

    passed &= DoDivTest(a, b);
    passed &= DoDivTest(a, -b);
    passed &= DoDivTest(-a, b);
    passed &= DoDivTest(-a, -b);

    return passed;
}


bool CheckDivTest(int64_t a, int64_t b)
{
    bool passed = CheckAllDivTest(a, b);
    if (passed)
        std::cout << "PASSED: DivTest(" << a << ", " << b << ")\n";
    return passed;
}


bool DivisionTests()
{
    bool passed = true;

    passed &= CheckDivTest(14, 5);
    passed &= CheckDivTest(2134, 5);
    passed &= CheckDivTest(7, 15);
    passed &= CheckDivTest(101, 77);
    passed &= CheckDivTest(7767781, 77);
    passed &= CheckDivTest(7364, 339256);
    passed &= CheckDivTest(111155111, 66234);
    passed &= CheckDivTest(111155111, 111155112);

    return passed;
}