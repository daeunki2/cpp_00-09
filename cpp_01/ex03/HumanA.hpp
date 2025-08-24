/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:24:20 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/24 00:57:04 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream> // cout, cin
#include <string> // string

class HumanA
{
	private:
	std::string		name;
	Weapon			&weapon; //subclass
	
	public:
	HumanA(std::string user_name, Weapon& weapon_type);
	~HumanA();
	void attack();
};

#endif
