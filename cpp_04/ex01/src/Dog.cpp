/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:24:37 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/31 21:24:45 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() // Default constructor
    : Animal("Dog")
{
    brain = new Brain("play");
    std::cout << "Dog created by default constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain); // 깊은 복사
    }
    std::cout << "Dog's copy assignment operator" << std::endl;
    return *this;
}

Dog::Dog(const Dog& src)
    : Animal(src) // Copy constructor
{
    brain = new Brain(*src.brain);
    std::cout << "Dog's copy constructor" << std::endl;
}

Dog::~Dog() // Destructor
{
    delete brain; // 메모리 해제 필수
    std::cout << "Dog destroyed by destructor" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "wouf wouf" << std::endl;
}

std::string Dog::getType(void) const
{
    return Animal::getType();
}

void Dog::setIdea(const std::string& idea)
{
    brain->set_idea(idea);
}

void Dog::showIdea(int n) const
{
    std::cout << "Dog idea[" << n << "] = " << brain->get_idea(n) << std::endl;
}
