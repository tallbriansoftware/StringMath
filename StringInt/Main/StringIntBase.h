#pragma once

#include <string>

class StringInt;

class StringIntBase
{
public:
    StringIntBase();
    StringIntBase(int64_t x);
    StringIntBase(const StringIntBase& sib);
    explicit StringIntBase(const StringInt& foo);

    StringIntBase& operator=(const StringIntBase& rhs);

    void Clear();
    int Length() const;
    bool IsPositive() const;
    bool IsNegative() const;

    void Absolute();
    void Negate();

    StringIntBase AbsoluteValueOf() const;
    StringIntBase NegationOf() const;

    int64_t GetInt64() const;
    std::string ToString() const;

    int GetDigit(int idx) const;
    void SetDigit(int idx, int value);
    void TrimZeros();
    StringIntBase& Shift(int s);


    int CompareAbsoluteValue(const StringIntBase& a, const StringIntBase& b) const;
    int SpaceShip(const StringIntBase& a, const StringIntBase& b) const;

    // ====== comparison operators ======

    bool operator>(const StringIntBase& rhs) const;
    bool operator<(const StringIntBase& rhs) const;
    bool operator>=(const StringIntBase& rhs) const;
    bool operator<=(const StringIntBase& rhs) const;
    bool operator==(const StringIntBase& rhs) const;
    bool operator!=(const StringIntBase& rhs) const;

    void AccumulateAddSameSigns(const StringIntBase& term);
    StringIntBase Add(const StringIntBase& term) const;

    void AccumulateSubtractSmallerSameSigns(const StringIntBase& term);
    StringIntBase Subtract(const StringIntBase& subtrahend) const;

    StringIntBase& MultiplyBySingleDigit(int m);
//    StringIntBase MultiplyByScalar(int rhs) const;
    StringIntBase Multiply(const StringIntBase& rhs) const;

private:
    bool m_isNegative;
    std::string m_valueString;
};