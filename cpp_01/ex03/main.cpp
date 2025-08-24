/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:24:31 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/24 04:01:48 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	std::cout <<  "HumanA is created with a weapon, cuz his constructor takes weapon as a reference" << std::endl;  {
    Weapon  club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
  }
  

  std::cout <<  "HumanB is created without a weapon, cuz his constructor takes weapon's pointer" << std::endl;
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
