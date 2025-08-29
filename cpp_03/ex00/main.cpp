/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:08:43 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 03:50:54 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("a");
	ClapTrap b("b");

	a.attack("b");
	b.takeDamage(3);
	b.beRepaired(1);
	b.attack("a");
	a.takeDamage(100000);

	return 0;
}