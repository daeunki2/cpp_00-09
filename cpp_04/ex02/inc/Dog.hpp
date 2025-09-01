/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:24:42 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/31 23:02:23 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog  : public AAnimal
{
	private :
	Brain *brain;

	public : 
	Dog();//Default constructor
	Dog& operator=(const Dog& other);//Copy assignment operator
	Dog(const Dog& src);  //Copy constructor
	virtual~Dog();// Destructor

	void makeSound(void) const;
	std::string getType()const;
	void setIdea(const std::string& idea);
	void showIdea(int n) const;
};

#endif