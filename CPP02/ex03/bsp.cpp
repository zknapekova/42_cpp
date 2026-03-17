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


static Fixed	cross_product(Point const &p, Point const &q, Point const &r)
{
	return (q.getX() - p.getX())*(r.getY()-p.getY()) - \
(q.getY() - p.getY())*(r.getX()-p.getX());
}

static bool	is_positive(Fixed const &f)
{
	return (f.toInt() > 0);
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
		
	Fixed cp_ab = cross_product(a, b, point);
	Fixed cp_bc = cross_product(b, c, point);
	Fixed cp_ca = cross_product(c, a, point);
	
	if (cp_ab.toInt() == 0 || cp_ca.toInt() == 0 || cp_bc.toInt() == 0)
		return false;
	return is_positive(cp_ab) == is_positive(cp_ca) && is_positive(cp_ca) == is_positive(cp_bc);	
}
