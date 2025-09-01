/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:34:00 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/31 21:26:34 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private : 
	std::string		idea[100];

	public :
	Brain();
	Brain(std::string idea);
	Brain(const Brain &src);
	~Brain();
	Brain& operator=(const Brain& src);

	void set_idea(std::string idea);
	std::string get_idea(int n);
	
};

#endif