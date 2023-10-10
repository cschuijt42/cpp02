#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed(const int i);
		Fixed(const float f);

		Fixed& operator=(const Fixed& src);

		~Fixed();

		bool operator<(const Fixed& comp) const;
		bool operator>(const Fixed& comp) const;
		bool operator<=(const Fixed& comp) const;
		bool operator>=(const Fixed& comp) const;
		bool operator==(const Fixed& comp) const;
		bool operator!=(const Fixed& comp) const;

		Fixed& operator+(const Fixed& operand);
		Fixed& operator-(const Fixed& operand);
		Fixed& operator*(const Fixed& operand);
		Fixed& operator/(const Fixed& operand);

		Fixed& operator++( void );
		Fixed  operator++( int  );
		Fixed& operator--( void );
		Fixed  operator--( int  );

		int	 getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int	  toInt( void ) const;

		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed& max(const Fixed& a, const Fixed& b);

	private:
		int 			 value;
		static const int point = 8;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif
