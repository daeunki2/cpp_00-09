/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 00:06:15 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 04:17:35 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
	std::cout << "\033[32m" << "ScavTrap default constructor called"<< "\033[0m"<< std::endl;
};

ScavTrap::ScavTrap(std::string input)//여기서 원본의 생성자 사용 가능
{
	this->name = input;
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
	std::cout << "\033[32m" << "ScavTrap" << name << "constructor called" <<  "\033[0m" << std::endl;
};

ScavTrap::~ScavTrap()
{
	std::cout<< "\033[32m" << "ScavTrap " << name << "destructor called" << "\033[0m" << std::endl;
};

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	if (this != &src)
	{
		this->name = src.name;
		this->HitPoint = src.HitPoint;
		this->AttackDamage = src.AttackDamage;
		this->EnergyPoint = src.EnergyPoint;
	}
	std::cout << "\033[32m" << "ScavTrap operator =" << name <<" called" << "\033[0m" << std::endl;
	return (*this);
};

ScavTrap::ScavTrap(const ScavTrap& src)  
{
	*this = src;
	std::cout << "\033[32m" << "ScavTrap copy constructor" << name <<" called" << "\033[0m" << std::endl;
};

void	ScavTrap::guardGate()
{
	std::cout << "\033[32m" << "ScavTrap " << name << "'s Gate keeper mode is on now!\n";
};

void ScavTrap::attack(const std::string& target)
{
    if (HitPoint > 0 && EnergyPoint > 0)
    {
        EnergyPoint--;
        std::cout << "\033[32m" << "ScavTrap " << name << " attacks " << target
                  << ", causing " << AttackDamage << " points of damage!" << "\033[0m" <<std::endl;
    }
    else
    {
        std::cout << "\033[32m" << "ScavTrap " << name << " has no energy or is dead and can't attack."<< "\033[0m" <<std::endl;
    }
}