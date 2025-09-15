/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:51:43 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/15 17:25:51 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"
#include <iostream>

// int main(int argc, char **argv)
// {
//     if (argc != 2)
//     {
//         std::cerr << "Usage: ./convert <literal>" << std::endl;
//         return 1;
//     }
//     // std::cout << "---------from subject--------" << std::endl;
//     // ScalarConverter::convert("0");
//     // ScalarConverter::convert("nan");
//     // ScalarConverter::convert("42.0f");
    
//     // std::cout << "---------your choice--------" << std::endl;
//     ScalarConverter::convert(argv[1]);
    
//     return 0;
// }

int main()
{
    std::cout << "---------from subject--------" << std::endl;
    std::cout << "input = " << "[0]" <<std::endl;
    ScalarConverter::convert("0");
    std::cout << "\ninput = " << "[nan]" <<std::endl;
    ScalarConverter::convert("nan");
    std::cout << "\ninput = " << "[42.0f]" <<std::endl;
    ScalarConverter::convert("42.0f");
    
    std::string input;
    std::cout << "---------your choice--------" << std::endl;
    for (int i =0; i < 7; i++)
    {
        std::cout << "give me a string : ";
        std::getline(std::cin, input);
        if (input == "exit")
            break;
        std::cout << "your input = " << "[" << input << "]" <<std::endl;
        ScalarConverter::convert(input);
        std::cout << "----------------------" << std::endl;
    }

    return 0;
}