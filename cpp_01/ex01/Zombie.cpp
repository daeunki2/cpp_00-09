/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:57:48 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/07 16:05:09 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return nullptr;

    Zombie* horde = new Zombie[N];  // Zombie 객체 N개를 힙에 생성 (기본 생성자 호출됨)

    for (int i = 0; i < N; i++)
    {
        horde[i].setname(name);
    }

    return horde;
}