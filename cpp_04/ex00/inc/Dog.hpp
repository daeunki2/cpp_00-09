/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:24:42 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 12:29:10 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog  : public Animal
{
	private :

	public : 
	Dog();//Default constructor
	Dog& operator=(const Dog& other);//Copy assignment operator
	Dog(const Dog& src);  //Copy constructor
	virtual~Dog();// Destructor

	void makeSound(void) const;
	std::string getType()const;
};

#endif