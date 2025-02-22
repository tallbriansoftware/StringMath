#include "CompTests.h"

#include "StringInt.h"
#include <assert.h>
#include <iostream>


bool DoCompTest(int64_t a, int64_t b)
{
    StringInt asi(a);
    if ((long long)asi != a)
    {
        std::cout << "conversion of " << a << " to StringInt and back failed.  "
            << "long long " << (long long)asi << ", " << "StringInt " << asi.ToString() << std::endl;
    }
    StringInt bsi(b);
    if ((long long)bsi != b)
    {
        std::cout << "conversion of " << b << " to StringInt and back failed.  "
            << "long long=" << (long long)bsi << ", " << "StringInt " << bsi.ToString() << std::endl;
    }

    bool shouldBeEqual = (a == b);
    bool shouldBeNotEqual = (a != b);
    bool shouldBeGreater = (a > b);
    bool shouldBeGreaterOrEqual = (a >= b);
    bool shouldBeLess = (a < b);
    bool shouldBeLessOrEqual = (a <= b);

    bool isEqual = (asi == bsi);
    bool isNotEqual = (asi != bsi);
    bool isGreater = (asi > bsi);
    bool isGreaterOrEqual = (asi >= bsi);
    bool isLess = (asi < bsi);
    bool isLessOrEqual = (asi <= bsi);

    bool passed = true;
    if (isEqual != shouldBeEqual)
    {
        std::cout << "Equal Compare Failed.  " << a << " should "
            << (shouldBeEqual ? "" : " NOT ") << " Equal to " << b << std::endl;
        passed = false;
    }
    if (isNotEqual != shouldBeNotEqual)
    {
        std::cout << "Equal Compare Failed.  " << a << " should "
            << (shouldBeNotEqual ? "" : " NOT ") << " be NotEqual to " << b << std::endl;
        passed = false;
    }
    if (isGreater != shouldBeGreater)
    {
        std::cout << "Greater Compare Failed.  " << a << " should "
            << (shouldBeGreater ? "" : " NOT ") << " be Greater than " << b << std::endl;
        passed = false;
    }
    if (isGreaterOrEqual != shouldBeGreaterOrEqual)
    {
        std::cout << "GreaterOrEqual Compare Failed.  " << a << " should "
            << (shouldBeGreaterOrEqual ? "" : " NOT ") << " be GreaterOrEqual to " << b << std::endl;
        passed = false;
    }
    if (isLess != shouldBeLess)
    {
        std::cout << "Less Compare Failed.  " << a << " should "
            << (shouldBeLess ? "" : " NOT ") << " be Less than " << b << std::endl;
        passed = false;
    }
    if (isLessOrEqual != shouldBeLessOrEqual)
    {
        std::cout << "LessOrEqual Compare Failed.  " << a << " should "
            << (shouldBeLessOrEqual ? "" : " NOT ") << " be LessOrEqual to " << b << std::endl;
        passed = false;
    }

    return passed;
}


bool CheckAllCompTest(int64_t a, int64_t b)
{
    bool passed = true;

    passed &= DoCompTest(a, b);
    passed &= DoCompTest(a, -b);
    passed &= DoCompTest(-a, b);
    passed &= DoCompTest(-a, -b);

    return passed;
}


bool CheckCompTest(int64_t a, int64_t b)
{
    bool passed = CheckAllCompTest(a, b);
    if (passed)
        std::cout << "PASSED: ComparisonTest(" << a << ", " << b << ")\n";
    return passed;
}


bool CompTests()
{
    bool passed = true;

    passed &= CheckCompTest(1144, 331);
    passed &= CheckCompTest(0, 497);
    passed &= CheckCompTest(867, 0);
    passed &= CheckCompTest(4422, 4422);
    passed &= CheckCompTest(0, 0);
    passed &= CheckCompTest(1, 1);

    return passed;
}