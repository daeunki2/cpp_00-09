/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 00:06:19 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 06:40:42 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private :

	public :
	ScavTrap();//Default constructor
	~ScavTrap();// Destructor
	ScavTrap(std::string input);
	ScavTrap& operator=(const ScavTrap& other);//Copy assignment operator
	ScavTrap(const ScavTrap& src);  //Copy constructor
	//
	void guardGate();
	void attack(const std::string& target);
		
};

#endif