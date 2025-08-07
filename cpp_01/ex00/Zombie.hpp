/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:28:40 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/07 15:56:13 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream> // cout, cin
#include <string> // string

//class

class Zombie
{
private:
    std::string name;

public:
    Zombie(std::string user_input)
    {
        name = user_input;
    }
    ~Zombie(){}
    void announce(void)
    {
        std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    }
};


//function
void randomChump( std::string name);
Zombie* newZombie( std::string name);

#endif
