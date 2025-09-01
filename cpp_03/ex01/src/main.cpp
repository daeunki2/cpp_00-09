/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:08:43 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 04:46:38 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap robot("Scout");

    robot.attack("Enemy");//overload
	robot.ClapTrap::attack("enemy");//mother class
    robot.guardGate();//original

    return 0;
}