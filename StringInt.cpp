#include "StringInt.h"

#include <algorithm>

namespace
{
    std::string ConvertInt64ToVector(int64_t x)
    {
        std::string val;
        while (x > 0)
        {
            uint8_t d = x % 10;
            char digit = d + '0';
            val.push_back(digit);
            x /= 10;
        }
        return val;
    }
}


StringInt::StringInt()
    : m_valueString("0")
    , m_isNegitive(false)
{ }


StringInt::StringInt(int64_t x)
{
    m_isNegitive = false;
    if (x < 0)
    {
        m_isNegitive = true;
        x = -x;
    }
    m_valueString = ConvertInt64ToVector(x);
}


StringInt::StringInt(const StringInt& si)
    : m_isNegitive(si.m_isNegitive)
    , m_valueString(si.m_valueString)
{ }


StringInt::operator long long() const
{
    return GetInt();
}


StringInt& StringInt::operator=(const StringInt& rhs)
{
    m_valueString = rhs.m_valueString;
    return *this;
}


int StringInt::Length() const
{
    return (int)m_valueString.size();
}


std::string StringInt::ToString()
{
    std::string printable = m_valueString;

    std::reverse(std::begin(printable), std::end(printable));
    if (IsNegitive())
        printable = '-' + printable;
    return printable;
}

int StringInt::CompareAbsoluteValue(const StringInt& a, const StringInt& b) const
{
    if (a.Length() > b.Length())
        return 1;
    if (b.Length() > a.Length())
        return -1;

    // Same length numbers
    for (int i = a.Length() - 1; i >= 0; i--)
    {
        if (a.m_valueString[i] > b.m_valueString[i])
            return 1;
        if (a.m_valueString[i] < b.m_valueString[i])
            return -1;
    }
    return 0;
}

int StringInt::SpaceShip(const StringInt& a, const StringInt& b) const
{
    // Different signs
    if (a.IsPositive() != b.IsPositive())
    {
        if (a.IsPositive())
            return 1;
        return -1;
    }

    // Same signs
    int cmp = CompareAbsoluteValue(a, b);
    if (a.IsNegitive())
        return -cmp;
    return cmp;
}

// ====== comparison operators ======

StringInt StringInt::operator>(const StringInt& rhs) const
{
    int cmp = SpaceShip(*this, rhs);
    return cmp == 1;
}

StringInt StringInt::operator<(const StringInt& rhs) const
{
    int cmp = SpaceShip(*this, rhs);
    return cmp == -1;
}

StringInt StringInt::operator>=(const StringInt& rhs) const
{
    int cmp = SpaceShip(*this, rhs);
    return cmp > -1;

}

StringInt StringInt::operator<=(const StringInt& rhs) const
{
    int cmp = SpaceShip(*this, rhs);
    return cmp < 1;

}

StringInt StringInt::operator==(const StringInt& rhs) const
{
    int cmp = SpaceShip(*this, rhs);
    return cmp == 0;
}

StringInt StringInt::operator!=(const StringInt& rhs) const
{
    int cmp = SpaceShip(*this, rhs);
    return cmp != 0;
}

// =======  Addition Operators =============

StringInt StringInt::SimpleAddition(const StringInt& a, const StringInt& b) const
{
    StringInt result(0);
    int longest = a.Length() > b.Length() ? a.Length() : b.Length();

    int carry = 0;
    for (int i = 0; i < longest; i++)
    {
        int a_d = (i < a.Length()) ? a.m_valueString[i] - '0' : 0;
        int b_d = (i < b.Length()) ? b.m_valueString[i] - '0' : 0;
        int value = a_d + b_d + carry;
        carry = value / 10;
        char d = (value % 10) + '0';
        result.m_valueString.push_back(d);
    }
    if (carry > 0)
        result.m_valueString.push_back('1');

    return result;
}


StringInt StringInt::operator+(const StringInt& rhs) const
{
    if(this->IsPositive() && rhs.IsPositive())
        return SimpleAddition(*this, rhs);

    return StringInt(44);

    //StringInt result(0);
    //int longest = this->Length() > rhs.Length() ? this->Length() : rhs.Length();

    //int carry = 0;
    //for (int i = 0; i < longest; i++)
    //{
    //    int a_d = (i < this->Length()) ? this->m_valueString[i] - '0' : 0;
    //    int b_d = (i < rhs.Length()) ? rhs.m_valueString[i] - '0' : 0;
    //    int value = a_d + b_d + carry;
    //    carry = value / 10;
    //    char d = (value % 10) + '0';
    //    result.m_valueString.push_back(d);
    //}
    //if (carry > 0)
    //    result.m_valueString.push_back('1');

    //return result;
}


StringInt& StringInt::operator+=(const StringInt& rhs)
{
    StringInt sum = *this + rhs;
    *this = sum;
    return *this;
}

// ============= Subtraction operators ===========

StringInt StringInt::operator-(const StringInt& rhs) const
{
    StringInt result(0);
    return result;
}



StringInt StringInt::operator*(const StringInt& rhs) const
{
    const StringInt& longer = (this->Length() > rhs.Length()) ? *this : rhs;
    const StringInt& shorter = (this->Length() > rhs.Length()) ? rhs : *this;

    StringInt result(0);

    for (int i = 0; i < shorter.Length(); i++)
    {
        int d = shorter.m_valueString[i] - '0';
        StringInt line = longer;
        line.SingleMult(d);
        line.Shift(i);
        result += line;
    }
    return result;
}


StringInt& StringInt::operator*=(const StringInt& rhs)
{
    StringInt product = *this * rhs;
    *this = product;
    return *this;
}


StringInt StringInt::operator/(const StringInt& rhs) const
{
    return StringInt(0);
}


StringInt StringInt::operator!() const
{
    StringInt result(1);
    int64_t value = GetInt();

    for (int i = 1; i <= value; i++)
    {
        result *= i;
    }
    return result;
}


StringInt& StringInt::SingleMult(int m)
{
    if (m < 0 || m> 9)
        throw std::exception("Invalid Argument SingleMult()");

    StringInt result(0);

    int carry = 0;
    for (int i = 0; i < this->Length(); i++)
    {
        int d = this->m_valueString[i] - '0';
        int term = d * m + carry;
        carry = term / 10;
        int value = term % 10;
        result.m_valueString.push_back(value + '0');
    }
    if (carry > 0)
        result.m_valueString.push_back(carry + '0');
    *this = result;
    return *this;
}

bool StringInt::IsNegitive() const
{
    return m_isNegitive;
}

bool StringInt::IsPositive() const
{
    return !m_isNegitive;
}

StringInt& StringInt::Shift(int s)
{
    if (s > 0)
    {
        std::string zeros;
        while (s-- > 0)
        {
            zeros += '0';
        }
        m_valueString = zeros + m_valueString;
    }
    else if (s < 0)
    {
        s = -s;
        for (int i = s; i < Length(); i++)
            m_valueString[i - s] = m_valueString[s];
        m_valueString.resize(Length() - s);
    }
    return *this;
}

int64_t StringInt::GetInt() const
{
    int64_t prev = 0;
    int64_t val = 0;
    int64_t mag = 1;
    for (int i = 0; i < Length(); i++)
    {
        prev = val;
        val += (m_valueString[i] - '0') * mag;
        if (val < prev)
            throw std::exception("Value too Large for conversion to long long.");
        mag *= 10;
    }
    if (IsNegitive())
        val = -val;
    return val;
}
