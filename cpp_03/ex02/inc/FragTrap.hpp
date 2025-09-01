/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 04:12:31 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 04:15:10 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private :

	public :
	FragTrap();//Default constructor
	~FragTrap();// Destructor
	FragTrap(std::string input);
	FragTrap& operator=(const FragTrap& other);//Copy assignment operator
	FragTrap(const FragTrap& src);  //Copy constructor
	//
	void	highFivesGuys(void);
		
};

#endif