/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:45:23 by daeunki2          #+#    #+#             */
/*   Updated: 2025/07/11 23:51:09 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


Contact::Contact()
{
		first_name = "";
        last_name = "";
        nick_name = "";
        phone_number = "";
        darkest_secret = "";
}
bool	Contact::set_first_name(const std::string &str)
{
	std::string temp = safe_str(str);
	if (temp.empty())
	{
		std::cout << "please enter again." << std::endl;
		return false;
	}
	first_name = coupcoup(temp);
	return true;
}

bool	Contact::set_last_name(const std::string &str)
{
	std::string temp;
	temp = safe_str(str);
	if (temp == "")
	{
		std::cout << "please enter again." << std::endl;
		return false;
	}
	temp = coupcoup(temp);
	last_name = temp;
	return true;
}

bool	Contact::set_nick_name(const std::string &str)
{
	std::string temp;
	temp = safe_str(str);
	if (temp == "")
	{
		std::cout << "please enter again." << std::endl;
		return false;
	}
	temp = coupcoup(temp);
	nick_name = temp;
	return true;
}

bool	Contact::set_phone_number(const std::string &str)
{
	std::string temp;
	temp = safe_number(str);
	if (temp == "")
	{
		std::cout << "please enter again." << std::endl;
		return false;
	}
	temp = coupcoup(temp);
	phone_number = temp;
	return true;
}
bool	Contact::set_darkest_secret(const std::string &str)
{
	std::string temp;
	temp = safe_str(str);
	if (temp == "")
	{
		std::cout << "please enter again." << std::endl;
		return false;
	}
	temp = coupcoup(temp);
	darkest_secret = temp;
	return true;
}

void Contact::write_page()
{
	std::string user_input;
    while(true)
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, user_input);
        if (set_first_name(user_input))
		    break;
    }
	while (true)
    {
        std::cout << "Enter last name: ";
        std::getline(std::cin, user_input);
        if(set_last_name(user_input))
		    break;
    }
	while (true)
    {
        std::cout << "Enter nick name: ";
        std::getline(std::cin, user_input);
        if(set_nick_name(user_input))
			break;
    }
	while (true)
    {
        std::cout << "Enter number: ";
        std::getline(std::cin, user_input);
        if(set_phone_number(user_input))
			break;
    }
	while (true)
    {
        std::cout << "Enter darkest_secret: ";
        std::getline(std::cin, user_input);
        if(set_darkest_secret(user_input))
		    break;
    }
}