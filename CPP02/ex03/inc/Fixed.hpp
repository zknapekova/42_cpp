/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:40:06 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/15 17:14:00 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		
		Fixed operator+( const Fixed& right ) const;
		Fixed operator+( const int v ) const;
		Fixed operator+( const float v ) const;
		
		Fixed operator-( const Fixed& right ) const;
		Fixed operator-( const int v ) const;
		Fixed operator-( const float v ) const;
		
		Fixed operator*( const Fixed& right ) const;
		Fixed operator*( const int v ) const;
		Fixed operator*( const float v ) const;
		
		Fixed operator/( const Fixed& right ) const;
		Fixed operator/( const int v ) const;
		Fixed operator/( const float v ) const;

		bool operator>( const Fixed& right ) const;
		bool operator>( const int right ) const;
		bool operator>( const float right ) const;
		
		bool operator<( const Fixed& right ) const;
		bool operator<( const int right ) const;
		bool operator<( const float right ) const;
		
		bool operator>=( const Fixed& right ) const;
		bool operator>=( const int right ) const;
		bool operator>=( const float right ) const;
		
		bool operator<=( const Fixed& right ) const;
		bool operator<=( const int right ) const;
		bool operator<=( const float right ) const;
		
		bool operator==( const Fixed& right ) const;
		bool operator==( const int right ) const;
		bool operator==( const float right ) const;
		
		bool operator!=( const Fixed& right ) const;
		bool operator!=( const int right ) const;
		bool operator!=( const float right ) const;
		
		Fixed& 	operator++( void );
		Fixed 	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );
		
		static Fixed& min(Fixed &fp1, Fixed &fp2);
		static Fixed& max(Fixed &fp1, Fixed &fp2);
		static const Fixed& min(const Fixed &fp1, const Fixed &fp2);
		static const Fixed& max(const Fixed &fp1, const Fixed &fp2);

};

std::ostream& operator<<( std::ostream& outs, const Fixed& fixed );

Fixed operator+( const int v, const Fixed &right );
Fixed operator+( const float v, const Fixed &right );

Fixed operator*( const int v, const Fixed &righ );
Fixed operator*( const float v, const Fixed &right );

Fixed operator-( const int v, const Fixed &right );
Fixed operator-( const float v, const Fixed &right );

Fixed operator/( const int v, const Fixed &divisor );
Fixed operator/( const float v, const Fixed &divisor );

bool operator>( const int v, const Fixed &right );
bool operator>( const float v, const Fixed &right );

bool operator<( const int v, const Fixed &right );
bool operator<( const float v, const Fixed &right );

bool operator>=( const int v, const Fixed &right );
bool operator>=( const float v, const Fixed &right );

bool operator<=( const int v, const Fixed &right );
bool operator<=( const float v, const Fixed &right );

bool operator==( const int v, const Fixed &right );
bool operator==( const float v, const Fixed &right );

bool operator!=( const int v, const Fixed &right );
bool operator!=( const float v, const Fixed &right );

#endif
