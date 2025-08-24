/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:24:25 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/24 03:56:35 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"


	HumanB::HumanB(std::string name)
	{
		this->name = name;
		std::cout << name << " is created" << std::endl;
		return ;
	}

	HumanB::~HumanB()
	{
		std::cout << name << " is destroyed" << std::endl;
	}

	void HumanB::attack()
	{
		if (!weapon || weapon->getType().empty())
		{
			std::cout << this->name << " has no weapon" << std::endl;
		}
		else
		{
			std::cout << name << " attack with their " << weapon->getType() << std::endl;
		}
		return ;
	}
	
	void HumanB::setWeapon(Weapon& weapon_ref)
	{
			this->weapon = &weapon_ref;
			std::cout << name << "got a weapon" << std::endl;
	}