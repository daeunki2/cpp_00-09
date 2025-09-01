/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:08:43 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/31 18:10:36 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "===== Creating default DiamondTrap =====\n";
    DiamondTrap dt_default;
    dt_default.whoAmI();
    dt_default.printStatus();

    std::cout << "\n===== Creating named DiamondTrap =====\n";
    DiamondTrap dt_named("Manoi");
    dt_named.whoAmI();
    dt_default.printStatus();

    std::cout << "\n===== Copying DiamondTrap =====\n";
    DiamondTrap dt_copy(dt_named);
    dt_copy.whoAmI();
    dt_default.printStatus();

    std::cout << "\n===== Assigning DiamondTrap =====\n";
    dt_default = dt_named;
    dt_default.whoAmI();
    dt_default.printStatus();

    std::cout << "\n===== using both DiamondTrap =====\n";
    dt_named.guardGate();               
    dt_named.highFivesGuys();

    std::cout << "\n===== End of main =====\n";
    return 0;
}
