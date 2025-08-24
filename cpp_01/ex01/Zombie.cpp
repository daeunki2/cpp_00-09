/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:57:48 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/24 03:35:22 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//class function
Zombie::Zombie()
{
	std::cout <<"a new zombie is created" << std::endl;
}
Zombie::Zombie(std::string user_input)
{
    name = user_input;
	std::cout << name << " is created" << std::endl;
}
Zombie::~Zombie()
{
	std::cout << name << " is destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void	Zombie::setname(std::string name)
{
	this->name = name;
}


//function
Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0 || N > INT_MAX)
        return NULL;

    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        horde[i].setname(name);
    }

    return horde;
}