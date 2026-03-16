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


static void	test(Fixed const &res, float expected, std::string name)
{
	std::cout << "TEST: " << name << ": ";
	if (res.toFloat() == expected)
		std::cout << " PASSED\n";
	else
		std::cout << "FAILED: expected: " << expected << ", got: " << res << std::endl;
}

static void	test_comp(bool res, bool expected, std::string name)
{
	std::cout << "TEST: " << name << ": ";
	if (res == expected)
		std::cout << " PASSED\n";
	else
		std::cout << "FAILED: expected: " << expected << ", got: " << res << std::endl;
}


int main( void ) {

	int	i = 10;
	float f = 2.5f;
	Fixed fix_i = Fixed(30);
	Fixed const fix_f = Fixed(20.5f);
	Fixed r;

	//addition:
	test(fix_i + Fixed(20), 50.0f, "Addition of two fixed objects");
	test(fix_f + Fixed(20), 40.5f, "Addition of two fixed objects");
	test(fix_f + f, 23.0f, "Addition of a fixed object and float");
	test(fix_i + i, 40.0f, "Addition of a fixed object and int");
	test(i + fix_i, 40.0f, "Addition of an int and fixed object");
	test(f + fix_i, 32.5f, "Addition of a float and fixed object");

	//subtraction
	test(fix_i - Fixed(20), 10.0f, "Subtraction of two fixed objects");
	test(fix_f - Fixed(20), 0.5f, "Subtraction of two fixed objects");
	test(fix_f - f, 18.0f, "Subtraction of a float from a fixed object");
	test(fix_i - i, 20.0f, "Subtraction of an int from a fixed object");
	test(i - fix_i, -20.0f, "Subtraction of a fixed object from an int");
	test(f - fix_i, -27.5f, "Subtraction of a fixed object from a float");


	//multiplication
	test(fix_i * Fixed(10), 300.0f, "Multiplication of two fixed objects");
	test(fix_f * Fixed(20), 410.0f, "Multiplication of two fixed objects");
	test(fix_f * 1.5f, 30.75f, "Multiplication of a float and a fixed object");
	test(fix_i * 2, 60.0f, "Multiplication of an int and a fixed object");
	test(0.5f * fix_i, 15.0f, "Multiplication of a float and a fixed object");
	test(2 * fix_i, 60.0f, "Multiplication of an int and a fixed object");


	//division
	test(fix_i / Fixed(10), 3.0f, "Division of two fixed objects");
	test(fix_f / Fixed(0.5f), 41.0f, "Division of two fixed objects");
	test(fix_i / 10, 3.0f, "Division of a fixed object by an int");
	test(fix_i / 2.5f, 12.0f, "Division of a fixed object by a float");
	test(60 / fix_i, 2.0f, "Division of an int by a fixed object");
	test(92.25f / fix_f, 4.5f, "Division of a float by a fixed object");

	//r = 92.25f / 0;
	//std::cout << "## expected: 0, got: " << r << std::endl;

	//Comparison
	test_comp(fix_i > fix_f, true, "Testing >: comparing two fixed objects");
	test_comp(fix_i > 0, true, "Testing >: comparing fixed object with an int");
	test_comp(fix_i > 1.5f, true, "Testing >: comparing fixed object with a float");
	test_comp(1.5f > fix_i, false, "Testing >: comparing  float with a fixed object");
	test_comp(0 > fix_i, false, "Testing >: comparing int with a fixed object");
	test_comp(1.5f > fix_i, false, "Testing >: comparing float with a fixed object");


	test_comp(fix_i < 0, false, "Testing <: comparing fixed object with an int");
	test_comp(fix_i < 1.5f, false, "Testing <: comparing fixed object with a float");
	test_comp(fix_i < fix_f, false, "Testing <: comparing two fixed objects");
	test_comp(0 < fix_i, true, "Testing <: comparing int with a fixed object");
	test_comp(12.5f < fix_f, true, "Testing <: comparing float with a fixed object");

	
	test_comp(fix_i >= 0, true, "Testing >=: comparing fixed object with an int");
	test_comp(fix_i >= 1.5f, true, "Testing >=: comparing fixed object with a float");
	test_comp(fix_i >= fix_f, true, "Testing >=: comparing two fixed objects");
	test_comp(0 >= fix_i, false, "Testing >=: comparing int with a fixed object");
	test_comp(1.5f >= fix_i, false, "Testing >=: comparing float with a fixed object");


	test_comp(fix_i <= 0, false, "Testing <=: comparing fixed object with an int");
	test_comp(fix_i <= 1.5f, false, "Testing <=: comparing fixed object with a float");
	test_comp(fix_i <= fix_f, false, "Testing <=: comparing two fixed objects");
	test_comp(0 <= fix_i, true, "Testing <=: comparing int with a fixed object");
	test_comp(12.5f <= fix_f, true, "Testing <=: comparing float with a fixed object");


	test_comp(fix_i == 0, false, "Testing ==: comparing fixed object with an int");
	test_comp(fix_i == 1.5f, false, "Testing ==: comparing fixed object with a float");
	test_comp(fix_i == fix_f, false, "Testing ==: comparing two fixed objects");
	test_comp(0 == fix_i, false, "Testing ==: comparing int with a fixed object");
	test_comp(12.5f == fix_f, false, "Testing ==: comparing float with a fixed object");

	
	test_comp(fix_i != 30, false, "Testing !=: comparing fixed object with an int");
	test_comp(fix_i != 1.5f, true, "Testing !=: comparing fixed object with a float");
	test_comp(fix_i != fix_f, true, "Testing !=: comparing two fixed objects");
	test_comp(0 != fix_i, true, "Testing !=: comparing int with a fixed object");
	test_comp(12.5f != fix_f, true, "Testing !=: comparing float with a fixed object");



	return 0;
}
