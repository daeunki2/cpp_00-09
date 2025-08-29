/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:43:09 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 00:09:36 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream> // cout, cin
#include <cmath> //round

class ClapTrap
{
	private :
	std::string		name;
	unsigned int	HitPoint;
	unsigned int	EnergyPoint;
	unsigned int	AttackDamage;
	

	public :
	ClapTrap(); //Default constructor
    ClapTrap(std::string input); // Parameterized constructor
	ClapTrap& operator=(const ClapTrap& other);//Copy assignment operator
	ClapTrap(const ClapTrap& src);  //Copy constructor
    ~ClapTrap(); // Destructor

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif