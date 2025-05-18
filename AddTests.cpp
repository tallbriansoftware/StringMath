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

    if ((int64_t)csi != c)
    {
        std::cout << "+ FAIL: " << asi.ToString() << " + " << bsi.ToString() << " = " << csi.ToString()
            << " should be " << c << std::endl;
        passed = false;
    }

    if ((int64_t)dsi != c)
    {
        std::cout << "+= FAIL: " << asi.ToString() << " += " << bsi.ToString()
            << " makes " << dsi.ToString()
            << " should be " << c << std::endl;
        passed = false;
    }
    return passed;
}

bool DoAddStrTest(const std::string& aStr, const std::string& bStr, const std::string& resultStr)
{
    StringInt asi(aStr);
    StringInt bsi(bStr);
    StringInt resultsi(resultStr);

    bool passed = true;

    auto sumsi = asi + bsi;
    auto sumStr = sumsi.ToString();
    if (sumsi != resultsi || sumStr != resultStr)
    {
        std::cout << "+ FAIL: " << asi.ToString() << " + " << bsi.ToString() << " = " << sumsi.ToString()
            << " should be " << aStr << " + " << bStr << " = " << resultStr << std::endl;
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

bool CheckAddStrTest(const std::string& a, const std::string& b, const std::string& result)
{
    bool passed = DoAddStrTest(a, b, result);
    if (passed)
        std::cout << "PASSED: AddTest(" << a << ", " << b << ", " << result << ")\n";
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
    passed &= CheckAddStrTest("123456789123456789123456799", "876543210876543210876543210", "1000000000000000000000000009");
    passed &= CheckAddStrTest("1111122222333334444455555", "-1111122222333334444455000", "555");

    return passed;
}

