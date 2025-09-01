/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:42:34 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/31 17:47:43 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "WrongCat.hpp"

WrongCat::WrongCat()//Default constructor
:WrongAnimal("WrongCat")
{
	std::cout << "WrongCat created by default constructor" << std::endl;
};
	
WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << "WrongCat's copy assignment operator" << std::endl;
    return *this;
}
	
WrongCat::WrongCat(const WrongCat& src)
:WrongAnimal(src) //Copy constructor
{	
	std::cout << "WrongCat's copy constructor" << std::endl;
};
	
WrongCat::~WrongCat()// Destructor
{
	std::cout << "WrongCat distroyed by destructor" << std::endl;
};
	

std::string WrongCat::getType(void) const
{
	return(WrongAnimal::getType());
}
