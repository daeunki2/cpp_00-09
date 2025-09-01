/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:39:49 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/31 16:50:44 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>


class WrongAnimal
{
	protected :
	std::string	type;
	
	public : 
	WrongAnimal();//Default constructor
	WrongAnimal(std::string type);
	WrongAnimal& operator=(const WrongAnimal& other);//Copy assignment operator
	WrongAnimal(const WrongAnimal& src);  //Copy constructor
	virtual~WrongAnimal();// Destructor

	virtual void makeSound(void) const;
	std::string getType(void) const;

};

#endif
