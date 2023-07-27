class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed& operator=(const Fixed& src);
		~Fixed();

		int	 getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int 			 value;
		static const int point = 8;
};
