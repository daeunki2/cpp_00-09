/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 00:32:05 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/01 00:38:45 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class	Cure : public AMateria
{

	public:
	Cure();
	Cure(const std::string &type);
	Cure(const Cure &src);
	Cure& operator=(const Cure &src);
	~Cure();
	 
	AMateria* clone() const; // override
    void use(ICharacter &target); // override
	
};

#endif