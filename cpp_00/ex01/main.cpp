/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:14:41 by daeunki2          #+#    #+#             */
/*   Updated: 2025/07/11 22:54:21 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    std::string     input;
    PhoneBook       phone_book;
    
    while (1)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, input);
        if (input == "ADD")
        {
            phone_book.add_1_page();
            phone_book.print_contact_at(0);
        }
        // else if (input == "SEARCH")
        // {
            
        // }
        // else if (input == "EXIT")
        // {
            
        // }
        else
        {
            std::cout << "Please, use correct command." << std::endl;
        }
    }
    return 0;
}