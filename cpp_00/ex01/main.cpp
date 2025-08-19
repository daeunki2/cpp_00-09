/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:14:41 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/19 19:30:01 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    std::string input;
    PhoneBook phone_book;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";

        if (!std::getline(std::cin, input))
        {
            std::cout << "\nEOF detected. Exiting.\n";
            break;
        }
        if (input == "ADD")
        {
            phone_book.add();
        }
        else if (input == "SEARCH")
        {
            phone_book.search();
        }
        else if (input == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Please, use a correct command." << std::endl;
        }
    }

    return 0;
}
