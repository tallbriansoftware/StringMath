#include "StringIntBase.h"

StringIntBase::StringIntBase()
    : m_valueString()
    , m_isNegative(false)
{ }

namespace
{
    std::string ConvertPositiveInt64ToString(int64_t x)
    {
        std::string val;
        if (x == 0)
            val = "0";
        else
        {
            while (x > 0)
            {
                uint8_t d = x % 10;
                char digit = d + '0';
                val.push_back(digit);
                x /= 10;
            }
        }
        return val;
    }
}

StringIntBase::StringIntBase(int64_t x)
{
    m_isNegative = false;
    if (x < 0)
    {
        m_isNegative = true;
        x = -x;
    }
    m_valueString = ConvertPositiveInt64ToString(x);
}

StringIntBase::StringIntBase(const StringIntBase& si)
    : m_isNegative(si.m_isNegative)
    , m_valueString(si.m_valueString)
{ }

StringIntBase& StringIntBase::operator=(const StringIntBase& rhs)
{
    m_valueString = rhs.m_valueString;
    m_isNegative = rhs.m_isNegative;
    return *this;
}

void StringIntBase::Clear()
{
    m_valueString.clear();
    m_isNegative = false;
}

int StringIntBase::Length() const
{
    return (int)m_valueString.size();
}

bool StringIntBase::IsPositive() const
{
    return !m_isNegative;
}

bool StringIntBase::IsNegative() const
{
    return m_isNegative;
}

void StringIntBase::Absolute()
{
    m_isNegative = false;
}

void StringIntBase::Negate()
{
    m_isNegative = !m_isNegative;
}

StringIntBase StringIntBase::NegationOf() const
{
    StringIntBase result(*this);
    if (result.Length() != 0)
        result.m_isNegative = !result.m_isNegative;
    return result;
}

StringIntBase StringIntBase::AbsoluteValueOf() const
{
    StringIntBase result(*this);
    if (result.Length() != 0)
        result.m_isNegative = false;
    return result;
}
std::string StringIntBase::ToString() const
{
    std::string printable = m_valueString;

    std::reverse(std::begin(printable), std::end(printable));
    if (IsNegative())
        printable = '-' + printable;
    return printable;
}

int64_t StringIntBase::GetInt64() const
{
    int64_t prev = 0;
    int64_t val = 0;
    int64_t mag = 1;

    if (Length() == 0)
        return 0;

    for (int i = 0; i < Length(); i++)
    {
        prev = val;
        val += (m_valueString[i] - '0') * mag;
        if (val < prev)
            throw std::exception("Value too Large for conversion to int64_t.");
        mag *= 10;
    }
    if (IsNegative())
        val = -val;
    return val;
}

int StringIntBase::GetDigit(int idx) const
{
    if (idx >= Length())
        return 0;

    return m_valueString[idx] - '0';
}

void StringIntBase::SetDigit(int idx, int value)
{
    if (value < 0 || value >= 10)
        throw std::exception("Value out of range for SetDigit");

    char ch = value + '0';
    if (idx < Length())
        m_valueString[idx] = ch;
    else if (idx == Length())
        m_valueString.push_back(ch);
    else
        throw std::exception("Index out of range for SetDigit");
}

void StringIntBase::TrimZeros()
{
    int last = Length() - 1;
    while (last >= 0 && m_valueString[last] == '0')
        last -= 1;

    int validLength = last + 1;
    if (validLength != Length())
        m_valueString.resize(validLength);
}

StringIntBase& StringIntBase::Shift(int s)
{
    if (Length() == 0)
        return *this;

    if (s > 0)
    {
        std::string zeros(s, '0');
        m_valueString = zeros + m_valueString;
    }
    else if (s < 0)
    {
        s = -s;
        m_valueString.erase(0, s);
    }
    return *this;
}

int StringIntBase::CompareAbsoluteValue(const StringIntBase& a, const StringIntBase& b) const
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

int StringIntBase::SpaceShip(const StringIntBase& a, const StringIntBase& b) const
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
    if (a.IsNegative())
        return -cmp;
    return cmp;
}

// ====== comparison operators ======

bool StringIntBase::operator>(const StringIntBase& rhs) const
{
    int cmp = SpaceShip(*this, rhs);
    return cmp == 1;
}

bool StringIntBase::operator<(const StringIntBase& rhs) const
{
    int cmp = SpaceShip(*this, rhs);
    return cmp == -1;
}

bool StringIntBase::operator>=(const StringIntBase& rhs) const
{
    int cmp = SpaceShip(*this, rhs);
    return cmp > -1;
}

bool StringIntBase::operator<=(const StringIntBase& rhs) const
{
    int cmp = SpaceShip(*this, rhs);
    return cmp < 1;
}

bool StringIntBase::operator==(const StringIntBase& rhs) const
{
    int cmp = SpaceShip(*this, rhs);
    return cmp == 0;
}

bool StringIntBase::operator!=(const StringIntBase& rhs) const
{
    int cmp = SpaceShip(*this, rhs);
    return cmp != 0;
}


void StringIntBase::AccumulateAddSameSigns(const StringIntBase& rhs)
{
    // If the signs are the same (pos or neg) we can just add the digits.
    if (this->IsPositive() != rhs.IsPositive())
        throw std::exception("accumulator and rhs need to have the same sign AccumulateAddPositive.");

    StringIntBase result;
    int longest = std::max(rhs.Length(), this->Length());

    int carry = 0;
    for (int i = 0; i < longest; i++)
    {
        int a_d = this->GetDigit(i);
        int b_d = rhs.GetDigit(i);
        int value = a_d + b_d + carry;
        carry = value / 10;
        value = value % 10;
        this->SetDigit(i, value);
    }
    if (carry > 0)
        this->SetDigit(longest, 1);
}

StringIntBase StringIntBase::Add(const StringIntBase& rhs) const
{
    StringIntBase result;

    // If the signs are the same (pos or neg)
    // Then just add the digits and keep the sign.
    if (this->IsPositive() == rhs.IsPositive())
    {
        result = *this;
        result.AccumulateAddSameSigns(rhs);
    }
    else
    {
        // If the signs are different:
        // Flip the sign on the negative one
        // Subtract it from the positive one.
        if (this->IsNegative())
        {
            StringIntBase subtrahend = this->NegationOf();
            result = rhs.Subtract(subtrahend);
        }
        else
        {
            StringIntBase subtrahend = rhs.NegationOf();
            result = this->Subtract(subtrahend);
        }
    }
    return result;
}

void StringIntBase::AccumulateSubtractSmallerSameSigns(const StringIntBase& rhs)
{
    if (this->IsNegative() != rhs.IsNegative())
        throw std::exception("accumulator and rhs must have the same sign in AccumulateSubtractSmallerPositive.");

    if(CompareAbsoluteValue(*this, rhs) == -1)
        throw std::exception("rhs must be less than or equal to Accumulator in AccumulateSubtractSmallerPositive.");

    bool borrow = false;
    for (int i = 0; i < this->Length(); i++)
    {
        int a_d = this->GetDigit(i);
        a_d -= (borrow ? 1 : 0);
        borrow = false;

        int b_d = rhs.GetDigit(i);
        if (b_d > a_d)
            borrow = true;

        int value = a_d + (borrow ? 10 : 0) - b_d;
        this->SetDigit(i, value);
        char d = value + '0';
    }
    TrimZeros();
}

StringIntBase StringIntBase::Subtract(const StringIntBase& subtrahend) const
{
    StringIntBase result;

    // If both have the same sign it is easier.
    //
    if (this->IsPositive() == subtrahend.IsPositive())
    {
        // If the ABS(sub) is greater than ABS(this)
        // Then reverse the order
        // Negate the sign of the result.
        if(CompareAbsoluteValue(subtrahend, *this) == 1)
        {
            result = subtrahend;
            result.AccumulateSubtractSmallerSameSigns(*this);
            result.Negate();
        }
        else
        {
            result = *this;
            result.AccumulateSubtractSmallerSameSigns(subtrahend);
        }
    }
    else
    {
        // If the signs are different
        // reverse the sign on the Sub
        // Add them together.
        result = subtrahend.NegationOf();
        result.AccumulateAddSameSigns(*this);
    }
    return result;
}

StringIntBase& StringIntBase::MultiplyBySingleDigit(int m)
{
    if (m < 0 || m> 9)
        throw std::exception("Invalid Argument MultiplyBySingleDigit()");

    StringIntBase result;

    int carry = 0;
    int length = this->Length();
    for (int i = 0; i < length; i++)
    {
        int d = this->GetDigit(i);
        int value = d * m + carry;
        carry = value / 10;
        value = value % 10;
        result.SetDigit(i, value);
    }
    if (carry > 0)
        result.SetDigit(length, carry);
    *this = result;
    return *this;
}

//StringIntBase StringIntBase::MultiplyByScalar(int rhs) const
//{
//
//}

StringIntBase StringIntBase::Multiply(const StringIntBase& rhs) const
{
    const StringIntBase& longer = (this->Length() > rhs.Length()) ? *this : rhs;
    const StringIntBase& shorter = (this->Length() > rhs.Length()) ? rhs : *this;

    StringIntBase result;

    for (int i = 0; i < shorter.Length(); i++)
    {
        int d = shorter.GetDigit(i);
        StringIntBase line = longer;
        line.MultiplyBySingleDigit(d);
        line.Shift(i);
        result.AccumulateAddSameSigns(line);
    }

    if (longer.IsNegative() != shorter.IsNegative())
        result.m_isNegative = true;
    return result;
}
