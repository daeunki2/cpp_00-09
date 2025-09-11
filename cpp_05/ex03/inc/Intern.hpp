/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:09:48 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/11 17:04:54 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>//cin cout
#include <string>//string
#include <exception>//exception

class Intern
{
	public :
	//constructor
 	Intern();//default constructor
 	Intern(std::string input, int ToSign, int ToExcute);//constructor with default constructor
 	Intern(const Intern& src); //Copy constructor
	//destructor
	~Intern();//default Destructor
	
	//Copy assignment operator
 	Intern& operator=(const Intern& src);

	//member function
	AForm*	makeForm(std::string form_name, std::string target_name);
};



#endif