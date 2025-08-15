/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:17:30 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/15 04:30:03 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = triangle_area(a, b, c);
    Fixed areaPBC = triangle_area(point, b, c);
    Fixed areaAPC = triangle_area(a, point, c);
    Fixed areaABP = triangle_area(a, b, point);

	if (areaABC == (areaPBC + areaAPC + areaABP))
	{
		if (areaPBC > Fixed(0) && areaAPC > Fixed(0) && areaABP > Fixed(0))
			return true;
		return false;
	}
	return false;
}

Fixed triangle_area(Point const a, Point const b, Point const c)
{
    Fixed area = Fixed(0.5f) * std::abs(
        a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
        b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
        c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())
    );
    return area;
}
