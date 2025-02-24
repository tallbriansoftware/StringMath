#include "StringInt.h"

#include <algorithm>

StringInt::StringInt()
    : m_base()
{ }

StringInt::StringInt(int64_t x)
    : m_base(x)
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

int StringInt::SpaceShip(const StringInt& a, const StringInt& b) const
{
    return this->m_base.SpaceShip(a.m_base, b.m_base);
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

// ============= Factorial operator ===========

StringInt StringInt::operator!() const
{
    StringInt result(1);
    int64_t value = m_base.GetInt64();

    for (int i = 1; i <= value; i++)
    {
        result *= i;
    }
    return result;
}
