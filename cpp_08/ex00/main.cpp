/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:43:00 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/22 10:59:13 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

int main()
{
    std::vector<int> myVector;
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);
    myVector.push_back(40);

    try
	{
        std::vector<int>::iterator result = easyfind(myVector, 30);
        std::cout << "Element found: " << *result << std::endl;

        std::vector<int>::iterator result2 = easyfind(myVector, 99);
        std::cout << "Element found: " << *result2 << std::endl;

    } 
	catch (const std::runtime_error& e)
	{
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}