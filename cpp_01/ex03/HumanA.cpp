/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:24:16 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/07 17:52:30 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

	HumanA::HumanA(std::string user_name, Weapon& weapon_type)
		: name(user_name), weapon(weapon_type)
	{
		
	}

	HumanA::~HumanA()
	{
		return ;
	}

	void HumanA::attack()
	{
		std::cout << name << " attack with their " << weapon.getType() << std::endl;
		return ;
	}
	