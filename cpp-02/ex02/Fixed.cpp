#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//? *************** CONSTRUCTORS ***************** //

Fixed::Fixed() : value(0) {};

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(const int value)
{
	this->value = value << Fixed::bits;
}

Fixed::Fixed(const float value)
{
	this->value = (int)roundf(value * (1 << Fixed::bits));
}

Fixed::~Fixed() {};

//? *************** OPERATORS ***************** //

Fixed &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->value = src.value;
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
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

//? *************** COMPARISON OPERATORS ***************** //

bool Fixed::operator>(const Fixed &src) const
{
	return this->value > src.value;
}

bool Fixed::operator<(const Fixed &src) const
{
	return this->value < src.value;
}

bool Fixed::operator>=(const Fixed &src) const
{
	return this->value >= src.value;
}

bool Fixed::operator<=(const Fixed &src) const
{
	return this->value <= src.value;
}

bool Fixed::operator==(const Fixed &src) const
{
	return this->value == src.value;
}

bool Fixed::operator!=(const Fixed &src) const
{
	return this->value != src.value;
}

//? *************** ARITHMETIC OPERATORS ***************** //

Fixed Fixed::operator+(const Fixed &src) const
{
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed &src) const
{
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed &src) const
{
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed &src) const
{
	return Fixed(this->toFloat() / src.toFloat());
}

Fixed &Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed &Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

//? *************** MIN/MAX ***************** //

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
