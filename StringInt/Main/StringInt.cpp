#include "StringInt.h"

#include <algorithm>

StringInt::StringInt()
    : m_base()
{ }

StringInt::StringInt(int64_t x)
    : m_base(x)
{ }

StringInt::StringInt(const std::string& str)
    : m_base(str)
{ }

StringInt::StringInt(const StringInt& si)
    : m_base(si.m_base)
{ }

StringInt::operator int64_t() const
{
    return m_base.GetInt64();
}

StringInt& StringInt::operator=(const StringInt& rhs)
{
    m_base = rhs.m_base;
    return *this;
}

std::string StringInt::ToString()
{
    return m_base.ToString();
}

// ====== comparison operators ======

bool StringInt::operator>(const StringInt& rhs) const
{
    int cmp = SpaceShip(rhs);
    return cmp == 1;
}

bool StringInt::operator<(const StringInt& rhs) const
{
    int cmp = SpaceShip(rhs);
    return cmp == -1;
}

bool StringInt::operator>=(const StringInt& rhs) const
{
    int cmp = SpaceShip(rhs);
    return cmp > -1;

}

bool StringInt::operator<=(const StringInt& rhs) const
{
    int cmp = SpaceShip(rhs);
    return cmp < 1;

}

bool StringInt::operator==(const StringInt& rhs) const
{
    int cmp = SpaceShip(rhs);
    return cmp == 0;
}

bool StringInt::operator!=(const StringInt& rhs) const
{
    int cmp = SpaceShip(rhs);
    return cmp != 0;
}

int StringInt::SpaceShip(const StringInt& rhs) const
{
    return this->m_base.SpaceShip(rhs.m_base);
}


// ====== addition operators ======

StringInt StringInt::operator+(const StringInt& rhs) const
{
    StringInt result;

    result.m_base = this->m_base.Add(rhs.m_base);
    return result;
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
    StringInt result;
    result.m_base = this->m_base.Subtract(rhs.m_base);
    return result;
}

StringInt& StringInt::operator-=(const StringInt& rhs)
{
    StringInt result = *this - rhs;
    *this = result;
    return *this;
}

// ============= Multiply operators ===========

StringInt StringInt::operator*(const StringInt& rhs) const
{
    StringInt product = *this;
    product.m_base = this->m_base.Multiply(rhs.m_base);
    return product;
}

StringInt& StringInt::operator*=(const StringInt& rhs)
{
    StringInt product;
    product.m_base = this->m_base.Multiply(rhs.m_base);
    *this = product;
    return *this;
}

// ============= IntDivide operators ===========

StringInt StringInt::operator/(const StringInt& rhs) const
{
    StringInt quotient;
    quotient.m_base = this->m_base.IntDivide(rhs.m_base);
    return quotient;
}

StringInt& StringInt::operator/=(const StringInt& rhs)
{
    StringInt quotient;
    quotient.m_base = this->m_base.IntDivide(rhs.m_base);
    *this = quotient;
    return *this;
}

// ============= Power operator ===============

StringInt StringInt::operator^ (int exp) const
{
    StringInt result(1);
    for (int i = 0; i < exp; i++)
        result *= *this;
    return result;
}

// ============= Factorial operator ===========

StringInt StringInt::operator!() const
{
    StringInt result(1);
    int64_t value = m_base.GetInt64();

    for (int i = 1; i <= value; i++)
    {
        StringInt isi(i);
        result *= isi;
    }
    return result;
}
