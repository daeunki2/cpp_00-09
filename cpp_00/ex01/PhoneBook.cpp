/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:54:29 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/05 10:58:33 by daeunki2         ###   ########.fr       */
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

void	PhoneBook::add()
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

	void PhoneBook::search()
	{
		std::string user_input;
		int temp;
	
    if (Contact_Count < 1)
	{
		std::cout << "this book is empty." << std::endl;
		return ;
	}

    show_all_contacts();
	
	std::cout << "enter an index to search" << std::endl;
	while(true)
	{
		std::getline(std::cin, user_input);
		
		try
   		{
       		temp = std::stoi(user_input);
 		}	
   		catch (const std::exception &e)
		{
       		std::cout << "Invalid input. Please enter a valid number." << std::endl;
       		continue;
   		}
		if (temp < 0 || temp >= Contact_Count)
   		{
   	    	std::cout << "Out if gange." << std::endl;
   	    	continue;
   		}
		break;
	}
	Pages[temp].print_a_detail_page();
};
	
void PhoneBook::show_all_contacts()
{
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "|   Index  |First Name|Last Name |Nick Name |" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	
	for (int i = 0; i < Contact_Count; i++)
		Pages[i].print_one_line(i);
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}