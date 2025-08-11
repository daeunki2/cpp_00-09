/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:13:38 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/11 20:36:54 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl        harl;
    std::string level;

    for (int i = 0; i < 7; i++)
    { 
      std::cout << "You can ask " << 7 - i << " questions" << std::endl;
      std::cout << "Enter complaint level (DEBUG, INFO, WARNING, ERROR): ";
      std::getline(std::cin, level);
      harl.complain(level);
    }
    return 0;
}