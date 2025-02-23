//#include "DivisionTests.h"
//#include "StringInt/StringInt.h"
//#include <iostream>
//
//bool DoDivTest(int64_t a, int64_t b)
//{
//    int64_t c = a / b;
//
//    StringInt asi(a);
//    StringInt bsi(b);
//    StringInt csi = asi / bsi;
//
//    //StringInt dsi = asi;
//    //dsi /= bsi;
//
//    bool passed = true;
//
//    if ((long long)csi != c)
//    {
//        std::cout << "/ FAIL: " << asi.ToString() << " / " << bsi.ToString() << " = (" << csi.ToString() << ")"
//            << " should be " << c << std::endl;
//
//        passed = false;
//    }
//
//    //int64_t d = (long long)dsi;
//
//    //if ((long long)dsi != c)
//    //{
//    //    std::cout << "*= FAIL: " << asi.ToString() << " *= " << bsi.ToString() << " makes " << dsi.ToString()
//    //        << "should be " << c << std::endl;
//    //    passed = false;
//    //}
//    return passed;
//}
//
//
//bool CheckDivTest(int64_t a, int64_t b)
//{
//    bool passed = DoDivTest(a, b);
//    if (passed)
//        std::cout << "PASSED: DivTest(" << a << ", " << b << ")\n";
//    return passed;
//}
//
//
bool DivisionTests()
{
    bool passed = true;

    //passed &= CheckDivTest(4, 5);
    //passed &= CheckDivTest(101, 77);
    //passed &= CheckDivTest(7364, 339256);
    //passed &= CheckDivTest(111155111, 66234);

    return passed;
}