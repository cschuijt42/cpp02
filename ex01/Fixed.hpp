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

		int	 getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int	  toInt( void ) const;

	private:
		int 			 value;
		static const int point = 8;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif
