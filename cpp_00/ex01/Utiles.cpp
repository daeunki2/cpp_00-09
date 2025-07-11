/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utiles.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:14:56 by daeunki2          #+#    #+#             */
/*   Updated: 2025/07/12 00:14:31 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string coupcoup(const std::string &temp)
{
    std::string final;

    if (temp.length() >= 10)
    {
        final = temp.substr(0, 9) + ".";
    }
    else
    {
        final = temp + std::string(10-temp.length(),' ');
    }
    return final;
}

std::string safe_str(const std::string &input)
{
    std::string ready;
    
    if (input.empty())
    {
        std::cout << "i need at least 1 alphabet" <<  std::endl;
        return "";
    }
    if (!is_alpha_string(input))
        return "";
    ready = trim(input);
    return ready;
};
std::string safe_number(const std::string &input)
{
    std::string ready;
    
    if (input.empty())
    {
        std::cout << "i need at least 1 number" <<  std::endl;
        return "";
    }
    if (!is_number_string(input))
        return "";
    ready = trim(input);
    return ready;
}
std::string trim(const std::string& str)
{
    size_t start = str.find_first_not_of(' ');
    if (start == std::string::npos)
    {
        std::cout << "i need at least 1 alphabet" <<  std::endl;
        return "";
    }
    size_t end = str.find_last_not_of(' ');
    return str.substr(start, end - start + 1);
};

bool is_alpha_string(const std::string &str)
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
        char c = *it;
        if (!std::isalpha(static_cast<unsigned char>(c)) && c != ' ')
        {
            std::cout << "[" << c << "]" << " is not an alphabet" << std::endl;
            return false;
        }
    }
    return true;
}

bool is_number_string(const std::string &str)
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
        char c = *it;
        if (!std::isdigit(static_cast<unsigned char>(c)) && c != ' ')
        {
            std::cout << "[" << c << "]" << " is not a digit" << std::endl;
            return false;
        }
    }
    return true;
}