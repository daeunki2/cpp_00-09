/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:24:16 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/24 03:56:31 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string user_name, Weapon& weapon_type)
    : name(user_name), weapon(weapon_type) // 초기화 리스트
{
	std::cout << name << " is created with a wepon"  << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << name << " is destroyed" << std::endl;
	return ;
}

void HumanA::attack()
{
	std::cout << name << " attack with their " << weapon.getType() << std::endl;
	return ;
}
	