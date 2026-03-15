/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:58:58 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/15 18:41:43 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
	const Fixed x;
	const Fixed y;
	
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& p);
		~Point();
		Point& operator=(const Point& p);
		const Fixed	getX(void) const;
		const Fixed	getY(void) const;

};

std::ostream& operator<<( std::ostream& outs, const Point& point );

bool bsp( Point const a, Point const b, Point const c, Point const point);