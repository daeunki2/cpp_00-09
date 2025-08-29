/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 04:12:26 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 06:57:10 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
: ClapTrap("default_frag_name", 100,100,30)
{
	std::cout << "\033[33m" << "FragTrap default constructor called"<< "\033[0m"<< std::endl;
};

FragTrap::FragTrap(std::string input)//여기서 원본의 생성자 사용 가능
{
	this->name = input;
	this->HitPoint = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
	std::cout << "\033[33m" << "FragTrap" << name << "constructor called" <<  "\033[0m" << std::endl;
};

FragTrap::~FragTrap()
{
	std::cout<< "\033[33m" << "FragTrap " << name << " destructor called" << "\033[0m" << std::endl;
};

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	if (this != &src)
	{
		this->name = src.name;
		this->HitPoint = src.HitPoint;
		this->AttackDamage = src.AttackDamage;
		this->EnergyPoint = src.EnergyPoint;
	}
	std::cout << "\033[33m" << "FragTrap operator =" << name <<" called" << "\033[0m" << std::endl;
	return (*this);
};

FragTrap::FragTrap(const FragTrap& src)  
{
	*this = src;
	std::cout << "\033[33m" << "FragTrap copy constructor" << name <<" called" << "\033[0m" << std::endl;
};

void	FragTrap:: highFivesGuys(void)
{
	std::cout << "\033[33m" << "FragTrap " << name << "'s Gate keeper mode is on now!\n";
};

