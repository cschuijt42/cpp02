#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() {
	std::cout << "Default constructor called." << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called." << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& src) {
	std::cout << "Copy assignment operator called." << std::endl;
	value = src.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called." << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called." << std::endl;
	return value;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called." << std::endl;
	value = raw;
}
