/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:41:54 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/31 17:46:42 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal()//Default constructor
:type("WrongAnimal")
{
	std::cout << "WrongAnimal created by defaukt constructor" << std::endl;
};

WrongAnimal::WrongAnimal(std::string type)//constructor
:type(type)
{
	std::cout << type <<"WrongAnimal created by default constructor" << std::endl;
};
	
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)//Copy assignment operator
{
	if(this != &other)
	{
		this->type = other.type;
	}
	std::cout << "WrongAnimal's Copy assignment operator" << std::endl;
	return(*this);
};
	
WrongAnimal::WrongAnimal(const WrongAnimal& src) //Copy constructor
{
	*this = src;
	std::cout << "WrongAnimal's copy constructor" << std::endl;
};
	
WrongAnimal::~WrongAnimal()// Destructor
{
		std::cout << "WrongAnimal distroyed by destructor" << std::endl;
};
	
void WrongAnimal::makeSound(void) const
{
		std::cout << "\033[31m"<< "unknown noise from somewhere!!!!!!!"<< "\033[0m" << std::endl; 
}

std::string WrongAnimal::getType(void) const
{
	return(type);
}