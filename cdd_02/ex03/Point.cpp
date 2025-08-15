/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:17:34 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/15 03:26:54 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
	
}
Point::Point(float const x1, float const y1) : x(x1), y(y1)
{
	
}
Point::Point(const Point& obj) : x(obj.getX()), y(obj.getY())
{
	
}
Point& Point::operator=(const Point& obj)
{
	if (this != &obj)
	{
		const_cast<Fixed&>(x) = obj.getX();
		const_cast<Fixed&>(y) = obj.getY();
	}
	return *this;
}

Point::~Point(void)
{
	
}
Fixed Point::getX(void) const
{
	return (x);
}

Fixed Point::getY(void) const
{
	return (y);
}