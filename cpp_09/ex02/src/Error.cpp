/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:10:05 by daeunki2          #+#    #+#             */
/*   Updated: 2025/11/12 12:11:14 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

/******************************************************************************/
/*                        	Orthodox Canonical Form                           */
/******************************************************************************/

PemergeMe_error::PemergeMe_error()
	: std::runtime_error("Unknown error"), _type(DEFAULT)
{
}

PemergeMe_error::PemergeMe_error(const std::string& msg, ErrorType type)
	: std::runtime_error(msg), _type(type)
{
}

PemergeMe_error::PemergeMe_error(const PemergeMe_error& other)
	: std::runtime_error(other.what()), _type(other._type)
{
}

PemergeMe_error& PemergeMe_error::operator=(const PemergeMe_error& other)
{
	if (this != &other)
	{
		*this = PemergeMe_error(other.what(), other._type);
	}
	return *this;
}

PemergeMe_error::~PemergeMe_error() throw() {}

/******************************************************************************/
/*                        	Orthodox Canonical Form                           */
/******************************************************************************/

void PemergeMe_error::print() const
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

PemergeMe_error::ErrorType PemergeMe_error::getType() const
{
	return _type;
}
