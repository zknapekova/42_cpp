#include "Fixed.hpp"

Fixed::Fixed():_fp_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int value )
{
	std::cout << "Int constructor called" << std::endl;
	
	if (value > _max_int_value || value < _min_int_value)
	{
		std::cerr << "ERROR: Value is too large\n";
		_fp_value = 0;
	}
	else
		_fp_value = value << _fract_bits;
	
	std::cout << _fp_value << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed& Fixed::operator=(const Fixed &orig)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_fp_value = orig.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fp_value;
}


void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_fp_value = raw;
}

