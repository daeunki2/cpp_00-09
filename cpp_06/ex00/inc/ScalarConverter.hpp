/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:51:37 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/15 17:06:13 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream> //cout, cin
#include <string> //string
#include <limits> //min, max value
#include <cmath>//round


enum Type
{
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_SPECIAL,
	TYPE_UNKNOWN
};

class ScalarConverter
{
    private: 
        ScalarConverter();
        ScalarConverter(const ScalarConverter &);
        ScalarConverter &operator=(const ScalarConverter &);
        ~ScalarConverter();

        // identifier
        static Type type_identifier(const std::string &str);
		
		static std::string trim(const std::string &str);
		static void	fromError(void);
        static bool is_Char(const std::string &trimmed);
        static bool is_Int(const std::string &trimmed);
        static bool is_Float(const std::string &trimmed);
        static bool is_Double(const std::string &trimmed);
        static bool is_Special(const std::string &trimmed);

        // printer
        static void fromChar(char c);
        static void fromInt(long i);
        static void fromFloat(float f);
        static void fromDouble(double d);
        static void handleSpecial(const std::string &str);

		//basic error
		class ScalarConverterException : public std::runtime_error
        {
            public:
                ScalarConverterException(const std::string& message);
        };

    public:
        static void convert(const std::string &literal);
};


#endif

