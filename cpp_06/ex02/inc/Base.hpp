/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:52:26 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/21 18:51:32 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include<iostream> //cin cout
#include<string> //str
#include <cstdlib> // rand(), srand()

class Base
{
	public : 
	virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif