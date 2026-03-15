/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:40:30 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/15 18:40:03 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {

	//testing Point class
	Point p = Point();
	std::cout << p << std::endl;
	
	Point q = Point(1.5f, 0.5f);
	std::cout << q << std::endl;

	
	
	return 0;
}
