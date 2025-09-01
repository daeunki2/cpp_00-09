/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:24:37 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/01 00:54:37 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()//Default constructor
:Animal("Dog")
{
	std::cout << "🐶Dog created by default constructor" << std::endl;
};
	
Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "🐶Dog's copy assignment operator" << std::endl;
    return *this;
}
	
Dog::Dog(const Dog& src)
:Animal(src) //Copy constructor
{	
	std::cout << "🐶Dog's copy constructor" << std::endl;
};
	
Dog::~Dog()// Destructor
{
	std::cout << "🐶Dog distroyed by destructor" << std::endl;
};
	
void Dog::makeSound(void) const
{
	std::cout << "🐶wouf wouf" << std::endl; 
}

std::string Dog::getType(void) const
{
	return(Animal::getType());
}