/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:43:09 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 06:56:46 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream> // cout, cin
#include <cmath> //round
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


class ClapTrap
{
	protected : //public? private? protected?
	std::string		name;
	unsigned int	HitPoint;
	unsigned int	EnergyPoint;
	unsigned int	AttackDamage;
	

	public :
	ClapTrap();//Default constructor
    ClapTrap(std::string input);
	ClapTrap(const ClapTrap& src);
	ClapTrap::ClapTrap(const std::string& n, int hp, int ep, int ad);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif