#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int value) : fixedPointValue(value << fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float value) : fixedPointValue(roundf(value * (1 << fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fixedPointValue = other.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits() const
{
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}

float Fixed::toFloat() const
{
    return ((float) this->fixedPointValue / (1 << fractionalBits));
}

int Fixed::toInt() const
{
    return this->fixedPointValue >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

// Comparison operators

bool Fixed::operator>(const Fixed &rhs) const
{
    return this->fixedPointValue > rhs.fixedPointValue;
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return this->fixedPointValue < rhs.fixedPointValue;
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return this->fixedPointValue >= rhs.fixedPointValue;
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return this->fixedPointValue <= rhs.fixedPointValue;
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return this->fixedPointValue == rhs.fixedPointValue;
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return this->fixedPointValue != rhs.fixedPointValue;
}

// Arithmetic operators

Fixed Fixed::operator+(const Fixed &rhs) const
{
    Fixed result;
    result.setRawBits(this->fixedPointValue + rhs.fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    Fixed result;
    result.setRawBits(this->fixedPointValue - rhs.fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    Fixed result;
    result.setRawBits((this->fixedPointValue * rhs.fixedPointValue) >> fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    if (rhs.fixedPointValue == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed();
    }
    Fixed result;
    result.setRawBits((this->fixedPointValue << fractionalBits) / rhs.fixedPointValue);
    return result;
}

// Increment/decrement operators

Fixed &Fixed::operator++()
{
    this->fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->fixedPointValue++;
    return temp;
}

Fixed &Fixed::operator--()
{
    this->fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->fixedPointValue--;
    return temp;
}

// Static min/max methods

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

