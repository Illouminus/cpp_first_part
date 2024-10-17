#include "Fixed.hpp"
#include <iostream>
#include <cmath>


Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = value << Fixed::bits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = (int)roundf(value * (1 << Fixed::bits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& src)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &src)
        this->value = src.getRawBits();
    return *this;
}

int Fixed::toInt(void) const
{
    return this->value >> bits;
}

float Fixed::toFloat(void) const
{
    return ((float)this->value) / (1 << bits);
}


int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat(); 
    return os;
}
