#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed(const int i);
		Fixed(const float f);

		Fixed& operator=(const Fixed& src);
		float  operator<<(const Fixed& src);

		~Fixed();

		int	 getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int	  toInt( void ) const;
	private:
		int 			 value;
		static const int point = 8;
};
