/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:45:23 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/19 19:27:54 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"


Contact::Contact()
{

}
Contact::~Contact()
{
	
}
//setters
void	Contact::set_first_name(const std::string& valid_input)
{
	first_name = valid_input;
}
void	Contact::set_last_name(const std::string& valid_input)
{
	last_name = valid_input;
}
void	Contact::set_nick_name(const std::string& valid_input)
{
	nick_name = valid_input;	
}
void	Contact::set_phone_number(const std::string& valid_input)
{
	phone_number = valid_input;	
}
void	Contact::set_darkest_secret(const std::string& valid_input)
{
	darkest_secret = valid_input;	
}
//getter
std::string	Contact::get_first_name() const
{
	return(first_name);
}

std::string	Contact::get_last_name() const
{
	return(last_name);

}

std::string	Contact::get_nick_name() const
{
	return(nick_name);

}
std::string	Contact::get_phone_number() const
{
	return(phone_number);

}
std::string	Contact::get_darkest_secret() const
{
	return(darkest_secret);
}
//utille
bool Contact::set_contacts(const std::string &user_input, Status flag)
{
	
	std::string temp;
	
	if (flag == P_NUM)
		temp = safe_number(user_input);
	else
		temp = safe_str(user_input);
	if(temp.empty())
	{
		std::cout << "please enter again." << std::endl;
		return false;
	}


	switch (flag)
    {
        case F_NAME:
            set_first_name(temp);
            break;
        case L_NAME:
            set_last_name(temp);
            break;
        case N_NAME:
            set_nick_name(temp);
            break;
        case P_NUM:
            set_phone_number(temp);
            break;
        case D_SECREAT:
            set_darkest_secret(temp);
            break;
        default:
            return false;
    }
	return true;
		
}

void Contact::add_page()
{
	const std::string prompts[] = 
	{
		"Enter first name: ",
        "Enter last name: ",
        "Enter nick name: ",
        "Enter number: ",
        "Enter darkest secret: ",
	};

	std::string user_input;
		
	for(int i = 0; i < FIELD_COUNT; ++i)
	{
		Status flag = static_cast<Status>(i);
		while (true)
		{
			std::cout << prompts[i]<<std::endl;
            std::getline(std::cin, user_input);
	        if (set_contacts(user_input, flag))
                break;
		}
	}
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
    ready = no_space(input);
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
    ready = no_space(input);
    return ready;
}

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

std::string no_space(const std::string& str) 
{ 
	size_t start = str.find_first_not_of(' ');
	if (start == std::string::npos)
	{ 
		std::cout << "i need at least 1 alphabet" << std::endl; return "";
	} 
	size_t end = str.find_last_not_of(' ');
	
	return str.substr(start, end - start + 1);
};