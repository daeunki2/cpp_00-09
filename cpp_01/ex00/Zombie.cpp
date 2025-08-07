/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:36:39 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/07 15:46:19 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// randomChump: Zombie 객체를 스택에 생성하고 announce
void randomChump(std::string name)
{
    Zombie baby(name);
    baby.announce();
}

// newZombie: Zombie 객체를 힙에 생성하고 포인터 반환
Zombie* newZombie(std::string name)
{
    return new Zombie(name);
}
