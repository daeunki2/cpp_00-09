/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:14:41 by daeunki2          #+#    #+#             */
/*   Updated: 2025/07/12 01:25:32 by daeunki2         ###   ########.fr       */
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
            phone_book.add();
        }
        else if (input == "SEARCH")
        {
            phone_book.search();
        }
        else if (input == "SEARCH")
        {
            phone_book.search();
        }
        else if (input == "EXIT")
        {
            break ;
        }
        else
        {
            std::cout << "Please, use correct command." << std::endl;
        }
    }
    return 0;
}