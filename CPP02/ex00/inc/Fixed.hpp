#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	int					_value;
	static const int	_fract_bits = 8;
	
	public:
		Fixed( void);
		Fixed(const Fixed& f);
		Fixed& operator=(const Fixed& orig);
		~Fixed( void );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

};


#endif
