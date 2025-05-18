#include "CtorTests.h"
#include "StringInt/StringInt.h"
#include <iostream>

bool DefaultCtorTest()
{
    StringInt sti;
    if (sti == 0)
        return true;
    return false;
}

bool IntCtorTest(int x)
{
    StringInt sti(x);
    if (sti == x)
        return true;
    std::cout << "Ctor FAIL: " << "(" << x << ")" << " resulted in " << sti.ToString() << std::endl;
    return false;
}

bool StringCtorTest(const std::string& str)
{
    StringInt sti(str);
    if (sti.ToString() == str)
        return true;
    std::cout << "Ctor FAIL: " << "(\"" << str << "\")" << " resulted in " << sti.ToString() << std::endl;
    return false;
}

bool CheckDefaultCtor()
{
    bool passed = DefaultCtorTest();
    if (passed)
        std::cout << "PASSED: DefaultCtorTest()\n";
    return passed;
}

bool CheckIntCtor(int x)
{
    bool passed = IntCtorTest(x);
    if (passed)
        std::cout << "PASSED: IntCtorTest(" << x << ")\n";
    return passed;
}

bool CheckStringCtor(const std::string& str)
{
    bool passed = StringCtorTest(str);
    if (passed)
        std::cout << "PASSED: StringCtorTest(\"" << str << "\")\n";
    return passed;
}


bool CtorTests()
{
    bool passed = true;

    passed &= CheckDefaultCtor();
    passed &= CheckIntCtor(2134);
    passed &= CheckStringCtor("123456");
    passed &= CheckStringCtor("-123456");
    passed &= CheckStringCtor("111222333444555666777888999000");

    return passed;
}