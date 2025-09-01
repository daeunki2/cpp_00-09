/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:24:33 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/31 23:02:56 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat  : public AAnimal
{
	private :
	Brain* brain;
	
	public : 
	Cat();//Default constructor
	Cat& operator=(const Cat& other);//Copy assignment operator
	Cat(const Cat& src);  //Copy constructor
	virtual~Cat();// Destructor

	void makeSound(void) const;
	std::string getType() const;
	void setIdea(const std::string& idea);
	void showIdea(int n);
};


#endif