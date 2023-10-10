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
	value = i * (1 << point);
}

Fixed::Fixed(const float f) {
	value = round(f * (1 << point));
}

// Assignment operator overloads

Fixed& Fixed::operator=(const Fixed& src) {
	std::cout << "Copy assignment operator called." << std::endl;
	value = src.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream &stream, const Fixed &fixed) {
	stream << fixed.toFloat();
	return stream;
}

// Arithmetic operator overloads

Fixed& Fixed::operator+(const Fixed& operand) {
	this->setRawBits(
		this->getRawBits() + operand.getRawBits()
	);
	return *this;
}

Fixed& Fixed::operator-(const Fixed& operand) {
	this->setRawBits(
		this->getRawBits() - operand.getRawBits()
	);
	return *this;
}

Fixed& Fixed::operator*(const Fixed& operand) {
	this->setRawBits(
		this->getRawBits() * operand.getRawBits()
	);
	return *this;
}

Fixed& Fixed::operator/(const Fixed& operand) {
	this->setRawBits(
		this->getRawBits() / operand.getRawBits()
	);
	return *this;
}

// Comparison operator overloads

bool Fixed::operator<(const Fixed& comp) const {
	return this->getRawBits() < comp.getRawBits();
}

bool Fixed::operator>(const Fixed& comp) const {
	return !(*this < comp);
}

bool Fixed::operator<=(const Fixed& comp) const {
	return (*this < comp) || (*this == comp);
}

bool Fixed::operator>=(const Fixed& comp) const {
	return (*this > comp) || (*this == comp);
}

bool Fixed::operator==(const Fixed& comp) const {
	return this->getRawBits() == comp.getRawBits();
}

bool Fixed::operator!=(const Fixed& comp) const {
	return !(*this == comp);
}

// Increment/decrement operator overloads

Fixed& Fixed::operator++( void ) {
	this->value++;
	return *this;
}

Fixed Fixed::operator++( int ) {
	Fixed temp(*this);
	operator++();

	return temp;
}

Fixed& Fixed::operator--( void ) {
	this->value--;
	return *this;
}

Fixed Fixed::operator--( int ) {
	Fixed temp(*this);
	operator--();

	return temp;
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
	return (float)(value) / (1 << point);
}

int	  Fixed::toInt( void ) const {
	return value >> point;
}

// Static functions

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a <= b)
		return a;
	else
		return b;
}

Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a <= b)
		return (Fixed&) a;
	else
		return (Fixed&) b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a >= b)
		return a;
	else
		return b;
}

Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a >= b)
		return (Fixed&) a;
	else
		return (Fixed&) b;
}
