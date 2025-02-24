#pragma once

#include "../main/stringintbase.h"

#include <inttypes.h>
#include <string>

class StringInt
{
public:
    StringInt();
    explicit StringInt(int64_t x);
    StringInt(const StringInt& si);

    std::string ToString();

    operator int64_t() const;
    StringInt& operator=(const StringInt& rhs);

    bool operator>(const StringInt& rhs) const;
    bool operator<(const StringInt& rhs) const;
    bool operator>=(const StringInt& rhs) const;
    bool operator<=(const StringInt& rhs) const;
    bool operator==(const StringInt& rhs) const;
    bool operator!=(const StringInt& rhs) const;
    
    StringInt operator+(const StringInt& rhs) const;
    StringInt& operator+=(const StringInt& rhs);

    StringInt operator-(const StringInt& rhs) const;
    StringInt& operator-=(const StringInt& rhs);

    StringInt operator*(const StringInt& rhs) const;
    StringInt& operator*=(const StringInt& rhs);

    StringInt operator/(const StringInt& rhs) const;
    StringInt& operator/=(const StringInt& rhs);

    StringInt operator!() const;

private:
    int SpaceShip(const StringInt& a, const StringInt& b) const;

    StringIntBase m_base;
};