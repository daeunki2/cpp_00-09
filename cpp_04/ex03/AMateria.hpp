/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 00:21:45 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/01 00:36:01 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class	ICharacter;

class	AMateria
{
	protected:
		std::string _type;
	
	public:
		AMateria();
		AMateria(const std::string &type);
		AMateria(const AMateria &src);
		AMateria& operator=(const AMateria &src);
		virtual ~AMateria();

		const std::string &getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
	
};

#endif