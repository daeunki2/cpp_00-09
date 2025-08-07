/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:24:41 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/07 17:56:11 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream> // cout, cin
#include <string> // string

class Weapon
{
	private:
	std::string		type;
	
	public:
	Weapon() {}
	Weapon(std::string type);
	~Weapon() {}
	const std::string &getType(void) const;
	void setType(const std::string& user_input);
};

#endif
