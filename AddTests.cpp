#include "AddTests.h"

#include "StringInt/StringInt.h"
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
        std::cout << "+= FAIL: " << asi.ToString() << " += " << bsi.ToString()
            << " makes " << dsi.ToString()
            << " should be " << c << std::endl;
        passed = false;
    }
    return passed;
}

bool CheckAllAddTest(int64_t a, int64_t b)
{
    bool passed = true;

    passed &= DoAddTest(a, b);
    passed &= DoAddTest(a, -b);
    passed &= DoAddTest(-a, b);
    passed &= DoAddTest(-a, -b);

    return passed;
}

bool CheckAddTest(int64_t a, int64_t b)
{
    bool passed = CheckAllAddTest(a, b);
    if (passed)
        std::cout << "PASSED: AddTest(" << a << ", " << b << ")\n";
    return passed;
}

bool AddTests()
{
    bool passed = true;

    passed &= CheckAddTest(1144, 331);
    passed &= CheckAddTest(222222, 22);
    passed &= CheckAddTest(100100, 10000);
    passed &= CheckAddTest(0, 324);
    passed &= CheckAddTest(0, 0);


    return passed;
}

