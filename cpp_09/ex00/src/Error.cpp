/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:25:17 by daeunki2          #+#    #+#             */
/*   Updated: 2025/11/08 12:27:25 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

/******************************************************************************/
/*                        	Orthodox Canonical Form                           */
/******************************************************************************/

Bitcoin_Error::Bitcoin_Error()
	: std::runtime_error("Unknown error"), _type(DEFAULT)
{
}

Bitcoin_Error::Bitcoin_Error(const std::string& msg, ErrorType type)
	: std::runtime_error(msg), _type(type)
{
}

Bitcoin_Error::Bitcoin_Error(const Bitcoin_Error& other)
	: std::runtime_error(other.what()), _type(other._type)
{
}

Bitcoin_Error& Bitcoin_Error::operator=(const Bitcoin_Error& other)
{
	if (this != &other)
	{
		*this = Bitcoin_Error(other.what(), other._type);
	}
	return *this;
}

Bitcoin_Error::~Bitcoin_Error() throw() {}

/******************************************************************************/
/*                        	Orthodox Canonical Form                           */
/******************************************************************************/

void Bitcoin_Error::print() const
{
	std::string color;

	switch (_type)
	{
		case FILE:   color = LIGHT_RED; break;
		case PARSE:  color = YELLOW; break;
		case VALUE:  color = CYAN; break;
		case DATE:   color = LIGHTMAGENTA; break;
		default:     color = RED; break;
	}

	std::cerr << color << "[Error] " << what() << RESET << std::endl;
}

Bitcoin_Error::ErrorType Bitcoin_Error::getType() const
{
	return _type;
}
