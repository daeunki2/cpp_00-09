/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:24:29 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/31 21:18:22 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()//Default constructor
:Animal("Cat")
{
	brain = new Brain("fish");
	std::cout << "Cat created by default constructor" << std::endl;
};
	
Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
	{
        Animal::operator=(other);
		delete brain;
        brain = new Brain(*other.brain);
	}
    std::cout << "Cat's copy assignment operator" << std::endl;
    return *this;
}
	
Cat::Cat(const Cat& src)
:Animal(src) //Copy constructor
{	
	brain = new Brain(*src.brain);
	std::cout << "Cat's copy constructor" << std::endl;
};
	
Cat::~Cat()// Destructor
{
	delete brain;
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

void Cat::setIdea(const std::string& idea)
{
    brain->set_idea(idea);
}

void Cat::showIdea(int n)
{
    std::cout << "Cat idea[" << n << "] = " << brain->get_idea(n) << std::endl;
}