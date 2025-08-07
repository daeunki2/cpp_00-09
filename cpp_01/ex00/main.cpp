/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:25:20 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/07 15:49:22 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "============= stackZombies =============" << std::endl;
	randomChump("randomChumpZ111");
	std::cout << "============= heapZombies ==============" << std::endl;
	Zombie	*heapZ;
   heapZ = newZombie("HeapZ");
	heapZ->announce();
   std::cout << "============= stackZombies =============" << std::endl;
	randomChump("randomChumpZ222");
	delete(heapZ);

	return (0);
}