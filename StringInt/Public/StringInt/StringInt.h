#pragma once

#include "../main/stringintbase.h"

#include <inttypes.h>
#include <string>

class StringInt
{
public:
    StringInt();
    StringInt(int64_t x);
    StringInt(const StringInt& si);

    std::string ToString();

    operator long long() const;
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

    StringInt operator!() const;

private:
    int SpaceShip(const StringInt& a, const StringInt& b) const;

    StringIntBase m_base;
};