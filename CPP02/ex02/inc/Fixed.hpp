#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <climits>
#include <cmath>

class Fixed
{
	int					_fp_value;
	static const int	_fract_bits = 8;
	static const int	_max_int_value = INT_MAX >> _fract_bits;
	static const int	_min_int_value = INT_MIN >> _fract_bits;
	
	public:
		Fixed( void );
		Fixed( const int value );
		Fixed( const float value );
		Fixed(const Fixed& f);
		~Fixed( void );
	
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		Fixed& operator=( const Fixed& orig );
		Fixed operator+( const Fixed& right );
		Fixed operator-( const Fixed& right );
		Fixed operator*( const Fixed& right );

};

std::ostream& operator<<( std::ostream& outs, const Fixed& fixed );


#endif
