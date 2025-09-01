/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:24:29 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/31 23:02:46 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()//Default constructor
:AAnimal("Cat")
{
	brain = new Brain("fish");
	std::cout << "Cat created by default constructor" << std::endl;
};
	
Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
	{
        AAnimal::operator=(other);
		delete brain;
        brain = new Brain(*other.brain);
	}
    std::cout << "Cat's copy assignment operator" << std::endl;
    return *this;
}
	
Cat::Cat(const Cat& src)
:AAnimal(src) //Copy constructor
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
	return(AAnimal::getType());
}

void Cat::setIdea(const std::string& idea)
{
    brain->set_idea(idea);
}

void Cat::showIdea(int n)
{
    std::cout << "Cat idea[" << n << "] = " << brain->get_idea(n) << std::endl;
}