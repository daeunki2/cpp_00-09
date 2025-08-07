/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:45:23 by daeunki2          #+#    #+#             */
/*   Updated: 2025/07/15 14:00:28 by daeunki2         ###   ########.fr       */
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

	temp = coupcoup(temp);
	    switch (flag)
    {
        case F_NAME:
            first_name = temp;
            break;
        case L_NAME:
            last_name = temp;
            break;
        case N_NAME:
            nick_name = temp;
            break;
        case P_NUM:
            phone_number = temp;
            break;
        case D_SECREAT:
            darkest_secret = temp;
            break;
        default:
            return false;
    }
	return true;
		
}

void Contact::write_page()
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

void Contact::print_a_detail_page()
{
	std::cout << "First Name     : " << first_name << std::endl;
	std::cout << "Last Name      : " << last_name << std::endl;
	std::cout << "NickName       : " << nick_name << std::endl;
	std::cout << "Phone          : " << phone_number <<std::endl;
	std::cout << "Darkest Secret : " << darkest_secret << std::endl;
}

void Contact::print_one_line(int index) const
{
	std::string index_str = coupcoup(std::to_string(index));
	std::cout << "|" << index_str
			  << "|" << first_name
			  << "|" << last_name
		  	  << "|" << nick_name
				<< "|" << std::endl;
}