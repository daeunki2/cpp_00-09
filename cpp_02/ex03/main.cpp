/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:25:20 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/25 15:44:33 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void show(Point const a, Point const b, Point const c, Point const p)
{
	std::cout << "abc = "<< triangle_area(a,b,c) <<
	 "  abp = " << triangle_area(a,b,p) << 
	 " acp = " << triangle_area(a,c,p) <<
	 " cbp = "<< triangle_area(b,c,p) << std::endl;

}

void correction(Point const a, Point const b, Point const c, Point const p)
{
	std::cout << "Point a = " << a.getX() << " " << a.getY() << std::endl;
	std::cout << "Point b = " << b.getX() << " " << b.getY() << std::endl;
	std::cout << "Point c = " << c.getX() << " " << c.getY() << std::endl;
	std::cout << "Point p = " << p.getX() << " " << p.getY() << std::endl;
	
	if (bsp(a, b, c, p))
	{
		show(a, b, c, p);
		std::cout << "abc = abp + acp + bcp" << std::endl;
		std::cout  << "\033[32m" << "it is in the triangle" << "\033[0m" << std::endl;
	}
	else
	{
		show(a, b, c, p);
		std::cout << "abc != abp + acp + bcp || " << 
		 "abp = 0 || acp = 0 || bcp = 0" << std::endl;
		std::cout << "\033[31m" <<"it is out of the triangle" << "\033[0m" << std::endl;
	}
}

int	main(void)
{
	Point	a(5, 5);
	Point	b(2, 9);
	Point	c(0, 5);
	Point	p(3, 7);
	Point	p2(4, 7);
	Point	p3(5, 5);
	Fixed	area;

	std::cout << "---------------------------"<<std::endl;
	correction(a, b, c, p);
	std::cout << "---------------------------"<<std::endl;
	correction(a, b, c, p2);
	std::cout << "---------------------------"<<std::endl;
	correction(a, b, c, p3);

	return 0;
}