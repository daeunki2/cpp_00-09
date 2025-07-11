/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:54:29 by daeunki2          #+#    #+#             */
/*   Updated: 2025/07/12 00:05:01 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	Contact_Count = 0;
	Oldest_Index = 0;
        for (int i = 0; i < 8; i++)
        	Pages[i] = Contact();
}

void	PhoneBook::add_1_page()
{
	Contact new_contact;
    int insert_index;

    new_contact.write_page();

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

void 	PhoneBook::print_contact_at(int index)
{
    if (index < 0 || index >= Contact_Count)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    Pages[index].print_contact(index);
}

