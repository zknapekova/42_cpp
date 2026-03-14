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
}

Fixed::Fixed( const float value )
{
	std::cout << "Float constructor called" << std::endl;
	
	if (value > _max_int_value || value < _min_int_value)
	{
		std::cerr << "ERROR: Value is too large\n";
		_fp_value = 0;
	}
	else
		_fp_value = roundf(value * (1 << _fract_bits));
		
	std::cout << _fp_value << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat( void ) const
{
	return static_cast<float>(_fp_value)/(1 << _fract_bits);
}

int	Fixed::toInt( void ) const
{
	return (_fp_value >> _fract_bits);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fp_value;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_fp_value = raw;
}

Fixed& Fixed::operator=( const Fixed &orig )
{
	std::cout << "Copy assignment operator called" << std::endl;
	_fp_value = orig.getRawBits();
	return *this;
}

std::ostream& operator<<( std::ostream& outs, const Fixed& fixed )
{
  outs << fixed.toFloat();
  return outs;
}

//adding two Fixed objects
Fixed Fixed::operator+( const Fixed& right )
{
	Fixed res;
	res.setRawBits(_fp_value + right.getRawBits());

	return res;
}

//detracting two Fixed objects
Fixed Fixed::operator-( const Fixed& right )
{
	Fixed res;
	res.setRawBits(_fp_value - right.getRawBits());

	return res;
}

//multiplying two Fixed objects
Fixed Fixed::operator*( const Fixed& right )
{
	Fixed res;
	if (_fp_value * right.getRawBits() > INT_MAX || \
	_fp_value * right.getRawBits() < INT_MIN)
		res.setRawBits(0);
	else
		res.setRawBits(_fp_value * right.getRawBits());

	return res;
}

//dividing two Fixed objects
Fixed Fixed::operator/( const Fixed& right )
{
	Fixed res;
	
	res.setRawBits(_fp_value / right.getRawBits());
	return res;
}


