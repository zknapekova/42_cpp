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
	
	Point a = Point(0.0f, 0.0f);
	Point b = Point(4.0f, 0.0f);
	Point c = Point(0.0f, 4.0f);

	std::cout << b << std::endl;

	// point inside the triangle
	bool res1 = bsp(a, b, c, Point(1.0f, 1.0f));
	std::cout << "1.result is " << res1 << std::endl;
	
	//point outside the triangle
	bool res2 = bsp(a, b, c, Point(5.0f, 5.0f));
	std::cout << "2.result is " << res2 << std::endl;
	
	//point is one of the vertices
	bool res3 = bsp(a, b, c, Point(0.0f, 0.0f));
	std::cout << "3.result is " << res3 << std::endl;
	
	//point is on the edge
	bool res4 = bsp(a, b, c, Point(3.0f, 0.0f));
	std::cout << "4.result is " << res4 << std::endl;
	return 0;
}
