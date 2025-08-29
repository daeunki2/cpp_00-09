/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 04:25:50 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 19:00:05 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public ClapTrap
{
	private :
		std::string	d_name;

	public :
	DiamondTrap();//Default constructor
	~DiamondTrap();// Destructor
	DiamondTrap(std::string input);
	DiamondTrap& operator=(const DiamondTrap& other);//Copy assignment operator
	DiamondTrap(const DiamondTrap& src);  //Copy constructor
	//
	void	whoAmI();
	void	showmetheadress();
		
};

#endif