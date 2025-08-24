/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:36:39 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/24 03:32:59 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string user_input)
{
    name = user_input;
	std::cout << name << " is created" << std::endl;
}
Zombie::~Zombie()
{
	std::cout << name << " is destroyed" << std::endl;
}
void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void randomChump(std::string name)
{
    Zombie baby(name);
    baby.announce();
}

Zombie* newZombie(std::string name)
{
    return new Zombie(name);
}
