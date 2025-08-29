/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:54:29 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 22:39:13 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	Contact_Count = 0;
	Oldest_Index = 0;
        for (int i = 0; i < 8; i++)
        	Pages[i] = Contact();
}

void	PhoneBook::add()
{
	Contact new_contact;
    int insert_index;

    new_contact.add_page();

    if (Contact_Count < 8)
    {
		insert_index = Contact_Count;
        Pages[insert_index] = new_contact;
        Contact_Count++;
    }
    else
    {
        insert_index = Oldest_Index;
        Pages[insert_index] = new_contact;
        Oldest_Index = (Oldest_Index + 1) % 8;
    }

    std::cout << "✅ Contact saved at index " << insert_index << std::endl;
}

void PhoneBook::search()
{
    std::string user_input;
    int temp;

    if (Contact_Count < 1)
    {
        std::cout << "this book is empty." << std::endl;
        return;
    }

    show_all_contacts();

    std::cout << "enter an index to search (0-" << Contact_Count - 1 << "): " << std::endl;
    while (true)
    {
        std::getline(std::cin, user_input);

        // 숫자인지 확인
        bool is_number = is_number_string(user_input);
        if (!is_number)
        {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            continue;
        }

        temp = std::atoi(user_input.c_str());

        if (temp < 0 || temp >= Contact_Count)
        {
            std::cout << "Out of range." << std::endl;
            continue;
        }

        break; // 유효한 입력이면 반복 종료
    }
	if (0 <= temp && temp <= Contact_Count)
    	show_detail_page(temp);
}

void	PhoneBook::show_detail_page(int index)
{
	std::cout << "First Name     : " << Pages[index].get_first_name() << std::endl;
	std::cout << "Last Name      : " << Pages[index].get_last_name() << std::endl;
	std::cout << "NickName       : " << Pages[index].get_nick_name() << std::endl;
	std::cout << "Phone          : " << Pages[index].get_phone_number() <<std::endl;
	std::cout << "Darkest Secret : " << Pages[index].get_darkest_secret() << std::endl;
}

void PhoneBook::show_all_contacts() const 
{
        std::cout << "┌──────────┬──────────┬──────────┬──────────┐\n";
        std::cout << "|   Index  |First Name|Last Name |Nick Name |\n";
        std::cout << "├──────────┼──────────┼──────────┼──────────┤\n";

        for (int i = 0; i < Contact_Count; i++) {
            std::cout << "|" << std::setw(10) << i
                      << "|" << std::right << std::setw(10) << fit(Pages[i].get_first_name())
                      << "|" << std::right << std::setw(10) << fit(Pages[i].get_last_name())
                      << "|" << std::right << std::setw(10) << fit(Pages[i].get_nick_name())
                      << "|" << std::endl;
        }

        std::cout << "└──────────┴──────────┴──────────┴──────────┘\n";
}


std::string fit(const std::string &s) 
{
        if (s.size() > 10) 
			return s.substr(0, 9) + ".";
        return s;
}