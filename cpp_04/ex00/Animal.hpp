/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:25:37 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 12:26:40 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>


class Animal
{
	protected :
	std::string type;

	public : 
	Animal();//Default constructor
	Animal(std::string type);
	Animal& operator=(const Animal& other);//Copy assignment operator
	Animal(const Animal& src);  //Copy constructor
	virtual~Animal();// Destructor

	virtual void makeSound(void) const;
	std::string getType(void) const;

};

#endif