#include "SubTests.h"

#include "StringInt/StringInt.h"
#include <assert.h>
#include <iostream>


bool DoSubTest(int64_t a, int64_t b)
{
    int64_t c = a - b;

    StringInt asi(a);
    StringInt bsi(b);
    StringInt csi = asi - bsi;

    StringInt dsi = asi;
    dsi -= bsi;

    bool passed = true;

    if ((int64_t)csi != c)
    {
        std::cout << "- FAIL: " << asi.ToString() << " - " << bsi.ToString() << " = " << csi.ToString()
            << " should be " << c << std::endl;
        passed = false;
    }

    if ((int64_t)dsi != c)
    {
        std::cout << "-= FAIL: " << asi.ToString() << " -= " << bsi.ToString()
            << " makes " << dsi.ToString()
            << " should be " << c << std::endl;
        passed = false;
    }

    return passed;
}

bool CheckAllSubTest(int64_t a, int64_t b)
{
    bool passed = true;

    passed &= DoSubTest(a, b);
    passed &= DoSubTest(a, -b);
    passed &= DoSubTest(-a, b);
    passed &= DoSubTest(-a, -b);

    return passed;
}


bool CheckSubTest(int64_t a, int64_t b)
{
    bool passed = CheckAllSubTest(a, b);
    if (passed)
        std::cout << "PASSED: SubTest(" << a << ", " << b << ")\n";
    return passed;
}


bool SubTests()
{
    bool passed = true;

    passed &= CheckSubTest(1144, 331);
    passed &= CheckSubTest(338, 226);
    passed &= CheckSubTest(1492, 1492);
    passed &= CheckSubTest(0, 1722);
    passed &= CheckSubTest(0, 0);

    return passed;
}

