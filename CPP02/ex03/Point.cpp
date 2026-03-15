/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:01:58 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/15 18:37:20 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( ): x(0), y(0)
{ }

Point::Point(const float x, const float y): x(Fixed(x)), y(Fixed(y))
{ }

Point::Point(const Point& p): x(p.getX()), y(p.getY())
{ }

Point& Point::operator=(const Point& orig)
{
	(void) orig;
	return *this;
}

Point::~Point()
{ }

std::ostream& operator<<( std::ostream& outs, const Point& point )
{
  outs << "Point[x = " << point.getX().toFloat() << ", y = " << point.getY().toFloat() << "]\n";
  return outs;
}


const Fixed	Point::getX(void) const
{
	return x;	
}

const Fixed	Point::getY(void) const
{
	return y;	
}