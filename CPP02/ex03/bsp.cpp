/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:30:38 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/15 18:45:50 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

int	is_vertex(Point const a, Point const b, Point const c, Point const point)
{
	if ((a.getX() == point.getX() && a.getY() == point.getY()) || \
(b.getX() == point.getX() && b.getY() == point.getY()) || \
(c.getX() == point.getX() && c.getY() == point.getY()))
		return 1;
	return 0;

}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (is_vertex(a, b, c, point))
		return false;
}