/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:24:31 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/07 17:57:36 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
  {
    Weapon  club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
  }
  {
	Weapon  club = Weapon("crude spiked club");

	HumanB jim("Jim");

	jim.setWeapon(club);

	jim.attack();

	club.setType("some other type of club");

	jim.attack();
  }
  return 0;
}
