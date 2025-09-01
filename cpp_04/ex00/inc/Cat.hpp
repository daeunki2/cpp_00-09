/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:24:33 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 12:29:06 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat  : public Animal
{
	private :

	public : 
	Cat();//Default constructor
	Cat& operator=(const Cat& other);//Copy assignment operator
	Cat(const Cat& src);  //Copy constructor
	virtual~Cat();// Destructor

	void makeSound(void) const;
	std::string getType() const;
};

#endif