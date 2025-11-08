/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:25:29 by daeunki2          #+#    #+#             */
/*   Updated: 2025/11/08 12:26:16 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
#define ERROR_HPP

#include <stdexcept>
#include <string>
#include <iostream>

#define RESET          "\x1B[0m"
#define RED            "\x1B[31m"
#define LIGHT_RED      "\x1B[91m"
#define YELLOW         "\x1B[33m"
#define CYAN           "\x1B[36m"
#define LIGHTMAGENTA   "\x1B[95m"

class Bitcoin_Error : public std::runtime_error
{
public:
	enum ErrorType
	{
		DEFAULT,
		FILE,
		PARSE,
		VALUE,
		DATE
	};

private:
	ErrorType _type;

public:
	//Orthodox Canonical Form
	Bitcoin_Error();														
	explicit Bitcoin_Error(const std::string& msg, ErrorType type = DEFAULT);
	Bitcoin_Error(const Bitcoin_Error& other);
	Bitcoin_Error& operator=(const Bitcoin_Error& other);
	virtual ~Bitcoin_Error() throw();

	void print() const;
	ErrorType getType() const;
};

#endif
