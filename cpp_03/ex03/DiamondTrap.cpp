/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 04:25:46 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/31 16:21:26 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap()
: ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), d_name("default")
{
    HitPoint = 100;     
    EnergyPoint = 50;   
    AttackDamage = 30;  
    std::cout  << "\033[34m" << "DiamondTrap default constructor" << "\033[0m" << std::endl;
}

// Constructor with name
DiamondTrap::DiamondTrap(std::string input)
: ClapTrap(input + "_clap_name"), ScavTrap(), FragTrap(), d_name(input)
{
    HitPoint = 100;     
    EnergyPoint = 50;   
    AttackDamage = 30;  
    std::cout << "\033[34m" << "DiamondTrap " << d_name << " constructor"<< "\033[0m" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& src)
: ClapTrap(src), ScavTrap(src), FragTrap(src), d_name(src.d_name)
{
    std::cout << "\033[34m" << "DiamondTrap " << d_name << " copy constructor"<< "\033[0m" << std::endl;
}

// Copy assignment
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        d_name = other.d_name;
        HitPoint = other.HitPoint;
        EnergyPoint = other.EnergyPoint;
        AttackDamage = other.AttackDamage;
    }
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "\033[34m"  << "DiamondTrap " << d_name << " destructor" << "\033[0m" << std::endl;
}

// Member functions
void DiamondTrap::whoAmI()
{
    std::cout << "\033[34m" << "DiamondTrap name: " << d_name 
              << ", ClapTrap name: " << ClapTrap::name << "\033[0m" << std::endl;
}

void DiamondTrap::printStatus(void)
{
	std::cout	<< "\033[34m" 
				<< "This DiamondTrap name is " << this->name << "\n"
				<< "HitPoint is " << HitPoint << "\n"
				<< "EnergyPoint is " << EnergyPoint << "\n"
				<< "AttackDamage is " << AttackDamage << "\033[0m" << std::endl;
}


