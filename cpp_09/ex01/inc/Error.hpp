/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:57:26 by daeunki2          #+#    #+#             */
/*   Updated: 2025/11/08 15:11:49 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ERROR_HPP
#define ERROR_HPP

#include <stdexcept>
#include <string>
#include <iostream>
#include "Error.hpp"

#define RESET          "\x1B[0m"
#define RED            "\x1B[31m"
#define LIGHT_RED      "\x1B[91m"
#define YELLOW         "\x1B[33m"
#define CYAN           "\x1B[36m"
#define LIGHTMAGENTA   "\x1B[95m"

class RPN_error : public std::runtime_error
{
public:
	enum ErrorType
	{
		DEFAULT,
		PARSE,
		LOGIC,
	};

private:
	ErrorType _type;

public:
	//Orthodox Canonical Form
	RPN_error();														
	explicit RPN_error(const std::string& msg, ErrorType type = DEFAULT);
	RPN_error(const RPN_error& other);
	RPN_error& operator=(const RPN_error& other);
	virtual ~RPN_error() throw();

	void print() const;
	ErrorType getType() const;
};

#endif

