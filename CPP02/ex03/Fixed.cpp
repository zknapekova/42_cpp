/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:40:12 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/15 17:20:32 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_fp_value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int value )
{
	//std::cout << "Int constructor called" << std::endl;
	
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
	//std::cout << "Float constructor called" << std::endl;
	
	if (value > _max_int_value || value < _min_int_value)
	{
		std::cerr << "ERROR: Value is too large\n";
		_fp_value = 0;
	}
	else
		_fp_value = roundf(value * (1 << _fract_bits));
}

Fixed::Fixed(const Fixed &f)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
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
	//std::cout << "getRawBits member function called" << std::endl;
	return _fp_value;
}

void	Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
	_fp_value = raw;
}

Fixed& Fixed::operator=( const Fixed &orig )
{
	//std::cout << "Copy assignment operator called" << std::endl;
	_fp_value = orig.getRawBits();
	return *this;
}

//insert operator overload
std::ostream& operator<<( std::ostream& outs, const Fixed& fixed )
{
  outs << fixed.toFloat();
  return outs;
}

//overload of the + operator for adding two Fixed objects
Fixed Fixed::operator+( const Fixed& right ) const
{
	Fixed res;
	long long fp;
	
	fp = static_cast<long long>(_fp_value) + right.getRawBits();
	if (fp > INT_MAX || fp < INT_MIN)
	{
		std::cerr << "ERROR: Integer overflow\n" << std::endl;
		res.setRawBits(0);
	}
	else
		res.setRawBits((_fp_value) + right.getRawBits());

	return res;
}

//overload of the + operator for adding Fixed object and int
Fixed Fixed::operator+( const int v ) const
{
	Fixed	right = Fixed(v);

	return *this + right;
}

//overload of the + operator for adding Fixed object and float
Fixed Fixed::operator+( const float v ) const
{
	Fixed	right = Fixed(v);

	return *this + right;
}

Fixed operator+( const int v, const Fixed &right )
{
	return right.operator+(v);
}

Fixed operator+( const float v, const Fixed &right )
{
	return right.operator+(v);
}


//overload of the - operator for subtracting two Fixed object
Fixed Fixed::operator-( const Fixed& right ) const
{
	Fixed res;
	long long int fp;
	
	fp = (static_cast<long long>(_fp_value)- right.getRawBits());
	if (fp < INT_MIN || fp > INT_MAX)
	{
		std::cerr << "ERROR: Integer overflow\n";
		res.setRawBits(0);
	}
	else
		res.setRawBits(_fp_value - right.getRawBits());

	return res;
}

//overload of the - operator for subtracting two Fixed objects
Fixed Fixed::operator-( const int v ) const
{
	Fixed	right = Fixed(v);
	return *this - right;
}

//overload of the - operator to subtract a float from a Fixed object
Fixed Fixed::operator-( const float v ) const
{
	Fixed	right = Fixed(v);
	return *this - right;
}

Fixed operator-( const int v, const Fixed &right )
{
	Fixed	left = Fixed(v);
	return left - right;
}

Fixed operator-( const float v, const Fixed &right )
{
	Fixed	left = Fixed(v);	
	return left - right;
}

//overload of the * operator to multiply two Fixed objects
Fixed Fixed::operator*( const Fixed& right ) const
{
	Fixed res;
	long long int fp;
	
	fp = (static_cast<long long>(_fp_value) * right.getRawBits()) >> _fract_bits;
	if (fp > INT_MAX || fp < INT_MIN)
	{
		std::cerr << "ERROR: Integer overflow\n" << std::endl;
		res.setRawBits(0);
	}
	else
		res.setRawBits((_fp_value * right.getRawBits()) >> _fract_bits);

	return res;
}


//overload of the * operator to multiply Fixed object by int
Fixed Fixed::operator*( const int v ) const
{
	Fixed right = Fixed(v);
	return *this * right;
}


//overload of the * operator to multiply Fixed object by float
Fixed Fixed::operator*( const float v ) const
{
	Fixed right = Fixed(v);
	return *this * right;
}

Fixed operator*( const int v, const Fixed &right )
{
	return right.operator*(v);
}

Fixed operator*( const float v, const Fixed &right )
{
	return right.operator*(v);
}

//overload of the / operator to divide two Fixed objects
Fixed Fixed::operator/( const Fixed& right ) const
{
	Fixed res;
	long long int fp;
	int	raw = right.getRawBits();

	if (raw == 0)
		res.setRawBits(0);
	
	fp = (static_cast<long long>(_fp_value) << _fract_bits) / right.getRawBits();
	if (fp > INT_MAX || fp < INT_MIN)
	{
		std::cerr << "ERROR: Integer overflow\n" << std::endl;
		res.setRawBits(0);
	}
	else
		res.setRawBits((_fp_value << _fract_bits) / right.getRawBits());
	
	return res;
}

//overload of the / operator to divide Fixed object by int
Fixed Fixed::operator/( const int v ) const
{
	Fixed divisor = Fixed(v);
	return *this / divisor;
}

//overload of the / operator to divide Fixed object by float
Fixed Fixed::operator/( const float v ) const
{
	Fixed divisor = Fixed(v);
	return *this / divisor;
}

Fixed operator/( const int v, const Fixed &divisor )
{
	Fixed dividend = Fixed(v);
	return dividend / divisor;
}

Fixed operator/( const float v, const Fixed &divisor )
{
	Fixed dividend = Fixed(v);
	return dividend / divisor;
}

//overload of the > operator to compare two Fixed objects
bool Fixed::operator>( const Fixed& right ) const
{
	return this->getRawBits() > right.getRawBits();
}

bool Fixed::operator>( const int right ) const
{
	return this->toInt() > right;
}

bool Fixed::operator>( const float right ) const
{
	return this->toFloat() > right;
}

bool operator>( const int v, const Fixed &right )
{
	return right <= v;
}

bool operator>( const float v, const Fixed &right )
{
	return right <= v;
}


bool Fixed::operator<( const Fixed& right ) const
{
	return this->getRawBits() < right.getRawBits();
}

bool Fixed::operator<( const int right ) const
{
	return this->toInt() < right;
}

bool Fixed::operator<( const float right ) const
{
	return this->toFloat() < right;
}

bool operator<( const int v, const Fixed &right )
{
	return right >= v;
}

bool operator<( const float v, const Fixed &right )
{
	return right >= v;
}

bool Fixed::operator>=( const Fixed& right ) const
{
	return this->getRawBits() >= right.getRawBits();
}

bool Fixed::operator>=( const int right ) const
{
	return this->toInt() >= right;
}

bool Fixed::operator>=( const float right ) const
{
	return this->toFloat() >= right;
}

bool operator>=( const int v, const Fixed &right )
{
	return right < v;
}

bool operator>=( const float v, const Fixed &right )
{
	return right < v;
}

bool Fixed::operator<=( const Fixed& right ) const
{
	return this->getRawBits() <= right.getRawBits();
}

bool Fixed::operator<=( const int right ) const
{
	return this->toInt() <= right;
}

bool Fixed::operator<=( const float right ) const
{
	return this->toFloat() <= right;
}

bool operator<=( const int v, const Fixed &right )
{
	return right > v;
}

bool operator<=( const float v, const Fixed &right )
{
	return right > v;
}

//overload of the == operator to compare two Fixed objects
bool Fixed::operator==( const Fixed& right ) const
{
	return this->getRawBits() == right.getRawBits();
}

bool Fixed::operator==( const int right ) const
{
	return this->toInt() == right;
}

bool Fixed::operator==( const float right ) const
{
	return this->toFloat() == right;
}

bool operator==( const int v, const Fixed &right )
{
	return right == v;
}

bool operator==( const float v, const Fixed &right )
{
	return right == v;
}

//overload of the != operator to compare two Fixed objects
bool Fixed::operator!=( const Fixed& right ) const
{
	return this->getRawBits() != right.getRawBits();
}

bool Fixed::operator!=( const int right ) const
{
	return this->toInt() != right;
}

bool Fixed::operator!=( const float right ) const
{
	return this->toFloat() != right;
}

bool operator!=( const int v, const Fixed &right )
{
	return right != v;
}

bool operator!=( const float v, const Fixed &right )
{
	return right != v;
}

Fixed&	Fixed::operator++( void )
{
	++this->_fp_value;
	return *this;
}

Fixed	Fixed::operator++( int )
{
	Fixed	res (*this);	
	++this->_fp_value;
	return res;
}

Fixed&	Fixed::operator--( void )
{
	--this->_fp_value;
	return *this;
}

Fixed	Fixed::operator--( int )
{
	Fixed	res (*this);
		
	--this->_fp_value;
	return res;
}

Fixed& Fixed::min(Fixed &fp1, Fixed &fp2)
{
	return (fp1 < fp2) ? fp1 : fp2;

}

Fixed& Fixed::max(Fixed &fp1, Fixed &fp2)
{
	return (fp1 > fp2) ? fp1 : fp2;
}

const Fixed& Fixed::min(const Fixed &fp1, const Fixed &fp2)
{
	return fp1 < fp2 ? fp1 : fp2;
}

const Fixed& Fixed::max(const Fixed &fp1, const Fixed &fp2)
{
	return (fp1 > fp2) ? fp1 : fp2;
}

