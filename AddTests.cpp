#include "AddTests.h"

#include "StringInt.h"
#include <assert.h>
#include <iostream>


bool DoAddTest(int64_t a, int64_t b)
{
    int64_t c = a + b;

    StringInt asi(a);
    StringInt bsi(b);
    StringInt csi = asi + bsi;

    StringInt dsi = asi;
    dsi += bsi;

    bool passed = true;

    if ((long long)csi != c)
    {
        std::cout << "+ FAIL: " << asi.ToString() << " + " << bsi.ToString() << " = " << csi.ToString()
            << " should be " << c << std::endl;
        passed = false;
    }

    if ((long long)dsi != c)
    {
        std::cout << "+= FAIL: " << asi.ToString() << " += " << bsi.ToString() << " makes " << dsi.ToString()
            << "should be " << c << std::endl;
        passed = false;
    }
    return passed;
}


bool CheckAddTest(int64_t a, int64_t b)
{
    bool passed = DoAddTest(a, b);
    if (passed)
        std::cout << "PASSED: AddTest(" << a << ", " << b << ")\n";
    return passed;
}


bool AddTests()
{
    bool passed = true;

    passed &= CheckAddTest(1144, 331);
    passed &= CheckAddTest(338, 226);
    passed &= CheckAddTest(678, 876);
    passed &= CheckAddTest(999867, 497);

    return passed;
}

