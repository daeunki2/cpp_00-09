/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 00:40:54 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/01 00:41:20 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class	Ice : public AMateria
{

	public:
	Ice();
	Ice(const std::string &type);
	Ice(const Ice &src);
	Ice& operator=(const Ice &src);
	~Ice();
	 
	AMateria* clone() const; // override
    void use(ICharacter &target); // override
	
};

#endif