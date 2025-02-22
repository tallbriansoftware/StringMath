#pragma once

#include <inttypes.h>
#include <string>

class StringInt
{
public:
    StringInt();
    StringInt(int64_t x);
    StringInt(const StringInt& si);

    std::string ToString();

    StringInt& operator=(const StringInt& rhs);

    StringInt operator>(const StringInt& rhs) const;
    StringInt operator<(const StringInt& rhs) const;
    StringInt operator>=(const StringInt& rhs) const;
    StringInt operator<=(const StringInt& rhs) const;
    StringInt operator==(const StringInt& rhs) const;
    StringInt operator!=(const StringInt& rhs) const;
    
    StringInt operator+(const StringInt& rhs) const;
    StringInt& operator+=(const StringInt& rhs);

    StringInt operator-(const StringInt& rhs) const;
    StringInt& operator-=(const StringInt& rhs);

    StringInt operator*(const StringInt& rhs) const;
    StringInt& operator*=(const StringInt& rhs);

    StringInt operator/(const StringInt& rhs) const;
    //StringInt& operator*=(const StringInt& rhs);

    StringInt operator!() const;

    operator long long() const;


private:
    void Clear();
    int Length() const;
    bool IsPositive() const;
    bool IsNegitive() const;
    StringInt Negation(const StringInt& a) const;
    StringInt AbsoluteValue(const StringInt& a) const;
    StringInt SimpleAddition(const StringInt& a, const StringInt& b) const;
    StringInt SimpleSubtraction(const StringInt& a, const StringInt& b) const;
    void SimpleSubtraction_FMBL(StringInt& result, const StringInt& larger, const StringInt& smaller) const;
    StringInt& SingleMult(int d);
    StringInt& Shift(int s);
    int64_t GetInt() const;
    int SpaceShip(const StringInt& a, const StringInt& b) const;
    int CompareAbsoluteValue(const StringInt& a, const StringInt& b) const;

    std::string m_valueString;
    bool m_isNegitive;
};