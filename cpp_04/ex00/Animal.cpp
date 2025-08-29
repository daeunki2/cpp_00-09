/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:25:41 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 12:14:19 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal()//Default constructor
:type("Animal")
{
	std::cout << "Animal created by defaukt constructor" << std::endl;
};

Animal::Animal(std::string type)//constructor
:type(type)
{
	std::cout << type <<"Animal created by defaukt constructor" << std::endl;
};
	
Animal& Animal::operator=(const Animal& other)//Copy assignment operator
{
	if(this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Animal's Copy assignment operator" << std::endl;
	return(*this);
};
	
Animal::Animal(const Animal& src) //Copy constructor
{
	*this = src;
	std::cout << "Animal's copy constructor" << std::endl;
};
	
Animal::~Animal()// Destructor
{
		std::cout << "Animal distroyed by destructor" << std::endl;
};
	
void Animal::makeSound(void) const
{
		std::cout << "unknown noise from somewhere" << std::endl; 
}

std::string Animal::getType(void) const
{
	return(type);
}