/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:43:21 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/31 16:56:16 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat  : public WrongAnimal
{
	private :

	public : 
	WrongCat();//Default constructor
	WrongCat& operator=(const WrongCat& other);//Copy assignment operator
	WrongCat(const WrongCat& src);  //Copy constructor
	virtual~WrongCat();// Destructor

	std::string getType() const;
};

#endif