/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:24:36 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/07 17:55:46 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

	Weapon::Weapon(std::string weapon_type)
	{
		type = weapon_type;
	}
	
	const std::string &Weapon::getType(void) const
	{
		return (type);
	}
	
	void Weapon::setType(const std::string& user_input)
	{
		this->type = user_input;
	}