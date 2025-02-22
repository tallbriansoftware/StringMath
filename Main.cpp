
#include "AddTests.h"
#include "SubTests.h"
#include "MultTests.h"
#include "FactorialTests.h"
#include "CompTests.h"

#include "StringInt.h"

#include <assert.h>
#include <iostream>


int main()
{
    bool passed = true;

    passed &= CompTests();
    passed &= AddTests();
    passed &= SubTests();
    passed &= MultTests();
    passed &= FactorialTests();
    //passed &= DivisionTests()

    if (passed)
        std::cout << "All Tests PASSED\n";
    else
        std::cout << "Test FAILED\n";
}

