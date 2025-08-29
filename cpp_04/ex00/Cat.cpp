/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:24:29 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 12:27:42 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()//Default constructor
:Animal("Cat")
{
	std::cout << "Cat created by default constructor" << std::endl;
};
	
Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Cat's copy assignment operator" << std::endl;
    return *this;
}
	
Cat::Cat(const Cat& src)
:Animal(src) //Copy constructor
{	
	std::cout << "Cat's copy constructor" << std::endl;
};
	
Cat::~Cat()// Destructor
{
	std::cout << "Cat distroyed by destructor" << std::endl;
};
	
void Cat::makeSound(void) const
{
	std::cout << "cat does not cry." << std::endl; 
}

std::string Cat::getType(void) const
{
	return(Animal::getType());
}
