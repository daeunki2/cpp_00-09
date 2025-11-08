/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:57:01 by daeunki2          #+#    #+#             */
/*   Updated: 2025/11/08 15:26:27 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

/******************************************************************************/
/*                        	Orthodox Canonical Form                           */
/******************************************************************************/

RPN_error::RPN_error()
	: std::runtime_error("Unknown error"), _type(DEFAULT)
{
}

RPN_error::RPN_error(const std::string& msg, ErrorType type)
	: std::runtime_error(msg), _type(type)
{
}

RPN_error::RPN_error(const RPN_error& other)
	: std::runtime_error(other.what()), _type(other._type)
{
}

RPN_error& RPN_error::operator=(const RPN_error& other)
{
	if (this != &other)
	{
		*this = RPN_error(other.what(), other._type);
	}
	return *this;
}

RPN_error::~RPN_error() throw() {}

/******************************************************************************/
/*                        	Orthodox Canonical Form                           */
/******************************************************************************/

void RPN_error::print() const
{
	std::string color;

	switch (_type)
	{
		case PARSE:  color = CYAN; break;
		case LOGIC:  color = RED; break;
		default:     color = LIGHTMAGENTA; break;
	}

	std::cerr << color << "[Error] " << what() << RESET << std::endl;
}

RPN_error::ErrorType RPN_error::getType() const
{
	return _type;
}
