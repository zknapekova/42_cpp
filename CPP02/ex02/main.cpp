/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:40:30 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/15 15:40:14 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

	int	i = 10;
	float f = 2.5f;
	Fixed fix_i = Fixed(30);
	Fixed const fix_f = Fixed(20.5f);
	Fixed r;

	//addition:
	r = fix_i + Fixed(20);
	std::cout << "## expected: 50, got: " << r << std::endl;

	r = fix_f + Fixed(20);
	std::cout << "## expected: 40.5, got: " << r << std::endl;

	r = fix_f + f;
	std::cout << "## expected: 23, got: " << r << std::endl;

	r = fix_i + i;
	std::cout << "## expected: 40, got: " << r << std::endl;

	r = i + fix_i;
	std::cout << "## expected: 40, got: " << r << std::endl;

	r = f + fix_i;
	std::cout << "## expected: 32.5, got: " << r << std::endl;

	//subtraction
	r = fix_i - Fixed(20);
	std::cout << "## expected: 10, got: " << r << std::endl;

	r = fix_f - Fixed(20);
	std::cout << "## expected: 0.5, got: " << r << std::endl;

	r = fix_f - f;
	std::cout << "## expected: 18, got: " << r << std::endl;

	r = fix_i - i;
	std::cout << "## expected: 20, got: " << r << std::endl;

	r = i - fix_i;
	std::cout << "## expected: -20, got: " << r << std::endl;

	r = f - fix_i;
	std::cout << "## expected: -27.5, got: " << r << std::endl;

	//multiplication
	r = fix_i * Fixed(10);
	std::cout << "## expected: 300, got: " << r << std::endl;

	r = fix_f * Fixed(20);
	std::cout << "## expected: 410, got: " << r << std::endl;

	r = fix_f * 1.5f;
	std::cout << "## expected: 30.75, got: " << r << std::endl;

	r = fix_i * 2;
	std::cout << "## expected: 60, got: " << r << std::endl;

	r = 0.5f * fix_i;
	std::cout << "## expected: 15, got: " << r << std::endl;

	r = 2 * fix_i;
	std::cout << "## expected: 60, got: " << r << std::endl;

	//division
	r = fix_i / Fixed(10);
	std::cout << "## expected: 3, got: " << r << std::endl;

	r = fix_f / Fixed(2.5f);
	std::cout << "## expected: 8.2, got: " << r << std::endl;

	r = fix_i / 10;
	std::cout << "## expected: 3, got: " << r << std::endl;

	r = fix_f / 10.25f;
	std::cout << "## expected: 2, got: " << r << std::endl;

	r = 60 / fix_i;
	std::cout << "## expected: 2, got: " << r << std::endl;

	r = 92.25f / fix_f;
	std::cout << "## expected: 4.5, got: " << r << std::endl;

	r = 92.25f / 0;
	std::cout << "## expected: 0, got: " << r << std::endl;

	//Comparison
	bool test = fix_i > fix_f;
	std::cout << "## expected: 1 (true), got: " << test << std::endl;
	
	test = fix_i > 0;
	std::cout << "## expected: 1 (true), got: " << test << std::endl;

	test = fix_i > 1.5f;
	std::cout << "## expected: 1 (true), got: " << test << std::endl;
	
	test = 0 > fix_i;
	std::cout << "## expected: 0 (false), got: " << test << std::endl;

	test = 1.5f > fix_i;
	std::cout << "## expected: 0 (false), got: " << test << std::endl;

	
	test = fix_i < 0;
	std::cout << "## expected: 0 (false), got: " << test << std::endl;

	test = fix_i < 1.5f;
	std::cout << "## expected: 0 (false), got: " << test << std::endl;
	
	test = fix_i < fix_f;
	std::cout << "## expected: 0 (false), got: " << test << std::endl;
	
	test = 0 < fix_i;
	std::cout << "## expected: 1 (true), got: " << test << std::endl;
	
	test = 12.5f < fix_f;
	std::cout << "## expected: 1 (true), got: " << test << std::endl;


	test = fix_i >= fix_f;
	std::cout << "## expected: 1 (true), got: " << test << std::endl;
	
	test = fix_i >= 0;
	std::cout << "## expected: 1 (true), got: " << test << std::endl;

	test = fix_i >= 1.5f;
	std::cout << "## expected: 1 (true), got: " << test << std::endl;

	test = 0 >= fix_i;
	std::cout << "## expected: 0 (false), got: " << test << std::endl;

	test = 1.5f >= fix_i;
	std::cout << "## expected: 0 (false), got: " << test << std::endl;


	test = fix_i <= 0;
	std::cout << "## expected: 0 (false), got: " << test << std::endl;

	test = fix_i <= 1.5f;
	std::cout << "## expected: 0 (false), got: " << test << std::endl;
	
	test = fix_i <= fix_f;
	std::cout << "## expected: 0 (false), got: " << test << std::endl;
	
	test = 0 <= fix_i;
	std::cout << "## expected: 1 (true), got: " << test << std::endl;
	
	test = 12.5f <= fix_f;
	std::cout << "## expected: 1 (true), got: " << test << std::endl;
	
	
	test = fix_i == 0;
	std::cout << "## expected: 0 (false), got: " << test << std::endl;

	test = fix_i == 1.5f;
	std::cout << "## expected: 0 (false), got: " << test << std::endl;
	
	test = fix_i == fix_f;
	std::cout << "## expected: 0 (false), got: " << test << std::endl;
	
	test = 0 == fix_i;
	std::cout << "## expected: 0 (false), got: " << test << std::endl;
	
	test = 12.5f == fix_f;
	std::cout << "## expected: 0 (false), got: " << test << std::endl;

	
	test = (fix_i != 30);
	std::cout << "## expected: 0 (false), got: " << test << std::endl;

	test = (fix_i != 1.5f);
	std::cout << "## expected: 1 (true), got: " << test << std::endl;
	
	test = (fix_i != fix_f);
	std::cout << "## expected: 1 (true), got: " << test << std::endl;
	
	test = (0 != fix_i);
	std::cout << "## expected: 1 (true), got: " << test << std::endl;
	
	test = (12.5f != fix_f);
	std::cout << "## expected: 1 (true), got: " << test << std::endl;


	
	/*std::cout << b << std::endl;
	Fixed const c( 3.3f + Fixed(30 ));
	std::cout << c << std::endl;*/
	/*std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;*/
	return 0;
}
