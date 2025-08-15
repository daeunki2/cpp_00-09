/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:17:38 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/15 04:08:40 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
 private:
	Fixed const x;
	Fixed const y;
 public:
	Point(void);
	Point(float const x, float const y);
	Point(const Point& obj);
	Point& operator=(const Point& obj);
	~Point(void);
	Fixed getX(void) const;
	Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
Fixed triangle_area(Point const a, Point const b, Point const c);


#endif