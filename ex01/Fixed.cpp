#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Constructors

Fixed::Fixed() {
	std::cout << "Default constructor called." << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called." << std::endl;
	*this = src;
}

Fixed::Fixed(const int i) {
	value = i << point;
}

Fixed::Fixed(const float f) {
	value = round(f * (2^point));
}

// Operator overloads

Fixed& Fixed::operator=(const Fixed& src) {
	std::cout << "Copy assignment operator called." << std::endl;
	value = src.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream &stream, const Fixed &fixed) {
	stream << fixed.toFloat();
	return stream;
}

// Destructor

Fixed::~Fixed() {
	std::cout << "Destructor called." << std::endl;
}

// Getters/setters

int	 Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called." << std::endl;
	return value;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called." << std::endl;
	value = raw;
}

// Member functions

float Fixed::toFloat( void ) const {
	return (float)value / (2^point);
}

int	  Fixed::toInt( void ) const {
	return value >> point;
}
