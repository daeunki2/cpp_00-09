/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 04:25:46 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 19:04:24 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap()//Default constructor
: ScavTrap(), FragTrap(), ClapTrap("default_clap_name")
{
	this->d_name = "default";
	this->HitPoint = FragTrap::HitPoint;
	this->EnergyPoint = ScavTrap::EnergyPoint;
	this->AttackDamage = ScavTrap::AttackDamage;
};

DiamondTrap::~DiamondTrap()// Destructor
{
	
};

DiamondTrap::DiamondTrap(std::string input);
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other);//Copy assignment operator
DiamondTrap::DiamondTrap(const DiamondTrap& src);  //Copy constructor
	//
void	DiamondTrap::whoAmI()
{

	
};
void	DiamondTrap::showmetheadress()
{

	
};
		
