/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:43:09 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 01:50:14 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream> // cout, cin
#include <cmath> //round

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
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif