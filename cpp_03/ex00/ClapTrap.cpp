/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:43:05 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/15 14:47:00 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap:: ClapTrap() : name("no_name"), HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string input) : name(input), HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
	std::cout << "ClapTrap " << name <<" constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	this->name = src.name;
	this->HitPoint = src.HitPoint;
	this->AttackDamage = src.AttackDamage;
	this->EnergyPoint = src.EnergyPoint;
	std::cout << "ClapTrap " << name <<" copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	if (this != &src)
	{
		this->name = src.name;
		this->HitPoint = src.HitPoint;
		this->AttackDamage = src.AttackDamage;
		this->EnergyPoint = src.EnergyPoint;
	}
	std::cout << "ClapTrap operator =" << name <<" called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
    if (HitPoint > 0 && EnergyPoint > 0)
    {
        EnergyPoint--;
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << AttackDamage << " points of damage!\n";
    }
    else
    {
        std::cout << "ClapTrap " << name << " has no energy or is dead and can't attack.\n";
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoint <= 0)
    {
        std::cout << "ClapTrap " << name << " is already dead.\n";
        return;
    }

    if (amount >= static_cast<unsigned int>(HitPoint))
    {
        HitPoint = 0;
        std::cout << "ClapTrap " << name << " loses all hit points!\n";
    }
    else
    {
        HitPoint -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage! Remaining HP: " << HitPoint << "\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (HitPoint > 0 && EnergyPoint > 0)
    {
        EnergyPoint--;
        HitPoint += amount;
        std::cout << "ClapTrap " << name << " repairs itself for " << amount
              << " points! Current HP: " << HitPoint << "\n";
    }
    else
    {
        std::cout << "ClapTrap " << name << " has no energy or is dead and can't repair.\n";
    }
}
