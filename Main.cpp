
#include "AddTests.h"
#include "MultTests.h"
#include "FactorialTests.h"
#include "CompTests.h"

#include "StringInt.h"

#include <assert.h>
#include <iostream>


int main()
{
    bool passed = true;

    passed &= AddTests();
    passed &= MultTests();
    passed &= FactorialTests();
    passed &= CompTests();
    //passed &= DivisionTests()

    if (passed)
        std::cout << "All Tests PASSED\n";
    else
        std::cout << "Test FAILED\n";
}

