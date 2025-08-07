/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:57:24 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/07 16:10:41 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
	Zombie *train;
	
	train = zombieHorde(10, "croissant");
	for (int i = 0; i < 10; i++)
	{
		std::cout << "no." << i << " ";
		train[i].announce();
	}
	delete [] train;
	return 0;
		
}