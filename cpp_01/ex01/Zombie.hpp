/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:57:41 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/23 21:28:05 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream> // cout, cin
#include <string> // string
#include <climits> // int_max

//class

class Zombie
{
private:
    std::string name;

public:
    Zombie();
	Zombie(std::string user_input);
    ~Zombie();
    void announce(void);
	void setname(std::string name);

};


//function
Zombie* zombieHorde( int N, std::string name);

#endif
