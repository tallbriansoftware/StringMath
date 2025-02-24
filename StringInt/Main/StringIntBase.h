#pragma once

#include <string>

class StringInt;

class StringIntBase
{
public:
    StringIntBase();
    StringIntBase(int64_t x);
    StringIntBase(const StringIntBase& sib);

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

    int CompareAbsoluteValue(const StringIntBase& rhs) const;
    int SpaceShip(const StringIntBase& rhs) const;

    // ====== comparison operators ======

    bool operator>(const StringIntBase& rhs) const;
    bool operator<(const StringIntBase& rhs) const;
    bool operator>=(const StringIntBase& rhs) const;
    bool operator<=(const StringIntBase& rhs) const;
    bool operator==(const StringIntBase& rhs) const;
    bool operator!=(const StringIntBase& rhs) const;

    StringIntBase Add(const StringIntBase& term) const;
    StringIntBase Subtract(const StringIntBase& subtrahend) const;
    StringIntBase Multiply(const StringIntBase& rhs) const;
    StringIntBase Divide(const StringIntBase& rhs) const;

private:
    // Shift is private because it depends on the numeric base used by the representaion.
    StringIntBase& Shift(int s);

    void AddSameSignsAcc(const StringIntBase& term);
    void SubtractSmallerSameSignsAcc(const StringIntBase& term);
    void MultiplyBySingleDigitAcc(int m);


private:
    bool m_isNegative;
    std::string m_valueString;
};