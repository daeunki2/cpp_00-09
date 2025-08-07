/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:57:41 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/07 16:11:51 by daeunki2         ###   ########.fr       */
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
    Zombie() {}
    ~Zombie() {}
    void announce(void)
    {
        std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    }
	void setname(std::string name)
	{
		this->name = name;
	}
};


//function
Zombie* zombieHorde( int N, std::string name);

#endif
