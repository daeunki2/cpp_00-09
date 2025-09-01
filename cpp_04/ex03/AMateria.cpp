/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 00:11:02 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/01 00:31:52 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(const std::string &type)
{
	_type = type;
}

AMateria::AMateria(const AMateria &src)
{
	_type = src._type;
}

AMateria& AMateria::operator=(const AMateria &src)
{
	if (this != &src)
		_type = src._type;
	return (*this);
}

AMateria::~AMateria()
{
	
}

const std::string& AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "Default attack (no type) on " << target.getName() << std::endl;
}