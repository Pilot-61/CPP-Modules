#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 fixedPointValue;
    static const int    fractionalBits = 8;
public:
    Fixed();
    Fixed(int value);
    ~Fixed();

    int     getRawBits() const;
    void    setRawBits(int const raw);
};

#endif