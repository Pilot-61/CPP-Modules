// Fixed.hpp
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 fixedPointValue;
    static const int    fraBits = 8;

public:
    Fixed();
    Fixed(int value);
    Fixed(float value);
    Fixed(const Fixed &other);
    ~Fixed();
    Fixed &operator=(const Fixed &other);

    bool operator>(const Fixed &oth) const;
    bool operator<(const Fixed &oth) const;
    bool operator>=(const Fixed &oth) const;
    bool operator<=(const Fixed &oth) const;
    bool operator==(const Fixed &oth) const;
    bool operator!=(const Fixed &oth) const;

    // Arithmetic operators
    Fixed operator+(const Fixed &oth) const;
    Fixed operator-(const Fixed &oth) const;
    Fixed operator*(const Fixed &oth) const;
    Fixed operator/(const Fixed &oth) const;

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif