/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:51:46 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/15 17:45:57 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

// ------------------------
// basic constructor destructor
// ------------------------
ScalarConverter::ScalarConverter()
{
    
};
ScalarConverter::ScalarConverter(const ScalarConverter &)
{

};
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &)
{
    return *this;
};
ScalarConverter::~ScalarConverter()
{
    
};

// ------------------------
// convert
// ------------------------
void ScalarConverter::convert(const std::string &literal)
{
    try {
        const std::string trimmed = trim(literal);
        Type s_type = type_identifier(trimmed);
        switch (s_type)
        {
            case TYPE_UNKNOWN:
                fromError();
                break;
            case TYPE_CHAR:
                fromChar(trimmed[0]);
                break;
            case TYPE_INT:
                fromInt(std::strtol(trimmed.c_str(), nullptr, 10));
                break;
            case TYPE_FLOAT:
                fromFloat(static_cast<float>(std::strtod(trimmed.c_str(), nullptr)));
                break;
            case TYPE_DOUBLE:
                fromDouble(std::strtod(trimmed.c_str(), nullptr));
                break;
            case TYPE_SPECIAL:
                handleSpecial(trimmed);
                break;
        }
    } catch (const ScalarConverterException& e)
    {
        std::cerr << e.what() << std::endl;
    }
}



// ------------------------
// identifier
// ------------------------
Type ScalarConverter::type_identifier(const std::string &str)
{
    if (is_Special(str))
        return (TYPE_SPECIAL);
    else if (is_Float(str))
        return (TYPE_FLOAT);
    else if (is_Double(str))
        return (TYPE_DOUBLE);
    else if (is_Int(str))
        return (TYPE_INT);
    else if (is_Char(str))
        return (TYPE_CHAR);
    else
        return (TYPE_UNKNOWN);
}
bool ScalarConverter::is_Char(const std::string &trimmed)
{
    // check the lenth. 
    if (trimmed.length() != 1)
        return (false);
    // 2. 숫자가 아닌 문자인지 확인
    if (std::isdigit(trimmed[0]))
        return false;
    return true;
}

bool ScalarConverter::is_Int(const std::string &trimmed)
{
    char *endptr;
    long value = std::strtol(trimmed.c_str(), &endptr, 10);

    if (*endptr != '\0')
        return false;
    if (value < std::numeric_limits<int>::min() && value > std::numeric_limits<int>::max())
        return false;
    return true;
}


bool ScalarConverter::is_Float(const std::string &trimmed)
{
    if (trimmed.back() != 'f' || trimmed.length() < 2)
    {
        return false;
    }
    char *endptr;
    std::strtod(trimmed.c_str(), &endptr);
    if (*endptr == 'f' && *(endptr + 1) == '\0')
        return true;
    return false;
}

bool ScalarConverter::is_Double(const std::string &trimmed)
{
    if (trimmed.find('.') == std::string::npos || trimmed.length() < 2)
    {
        return false;
    }
    char *endptr;
    std::strtod(trimmed.c_str(), &endptr);
    if (*endptr != '\0')
        return false;
    return true;
}


bool ScalarConverter::is_Special(const std::string &trimmed)
{
    if (trimmed ==  "-inf" || trimmed == "+inf" || trimmed  == "nan")
        return (true);
    else if (trimmed == "-inff" || trimmed == "+inff" || trimmed == "nanf")
        return (true);
    return(false);
}

// ------------------------
// printer
// ------------------------
void   ScalarConverter::fromError(void)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
void ScalarConverter::fromChar(char c)
{
    if (!std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;

    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout.precision(1);
    std::cout << std::fixed << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << std::fixed << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::fromInt(long value)
{
    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    std::cout << "int: " << static_cast<int>(value) << std::endl;

    std::cout.precision(1);
    std::cout << std::fixed << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << std::fixed << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::fromFloat(float f)
{
    if (std::isnan(f) || std::isinf(f) || f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(f)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    
    if (std::isnan(f) || std::isinf(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;

    std::cout.precision(1);
    std::cout << std::fixed << "float: " << f << "f" << std::endl;
    std::cout << std::fixed << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::fromDouble(double d)
{
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    
    if (std::isinf(d) || (d < -std::numeric_limits<float>::max() && d != -std::numeric_limits<float>::infinity()) 
         || (d > std::numeric_limits<float>::max() && d != std::numeric_limits<float>::infinity()))
        std::cout << "float: impossible" << std::endl;
    else
    {
        std::cout.precision(1);
        std::cout << std::fixed << "float: " << static_cast<float>(d) << "f" << std::endl;
    }

    std::cout.precision(1);
    std::cout << std::fixed << "double: " << d << std::endl;
}

void ScalarConverter::handleSpecial(const std::string &str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (str == "nan" || str == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (str == "+inf" || str == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (str == "-inf" || str == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}
// ------------------------
// basic error control
// ------------------------

std::string ScalarConverter::trim(const std::string &str)
{
    size_t i = 0;

    // 공백 건너뛰기
    while (i < str.length() && std::isspace(str[i]))
        i++;
    
    // 빈 문자열인 경우 예외 발생
    if (i == str.length())
        throw ScalarConverterException("Error: Empty string");

    size_t j = str.length() - 1;
    while (j > 0 && std::isspace(str[j]))
        j--;

    // 문자열 중간에 공백이 있는지 확인
    for (size_t k = i; k <= j; k++) {
        if (std::isspace(str[k])) {
            throw ScalarConverterException("Error: Whitespace in the middle of string");
        }
    }

    return str.substr(i, j - i + 1);
}
ScalarConverter::ScalarConverterException::ScalarConverterException(const std::string &m)
: std::runtime_error(m)
{
}