class Fixed
{
	public:
		Fixed();
		Fixed(Fixed &src);
		Fixed& operator=(Fixed& src);
		~Fixed();

		int	 getRawBits( void );
		void setRawBits( int const raw );
	private:
		int 			 value;
		static const int point = 8;
};
