/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:41:48 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/10 16:53:27 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"

int main()
{
    try
	{
        Bureaucrat a("Alice", 1);
        std::cout << a << std::endl;

        a.increment(); // 예외 발생
    }
	catch (const std::exception& e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
	std::cout << "\n\n\n"<< std::endl;
    try
	{
        Bureaucrat b("Bob", 151); // 예외 발생
    }
	catch (const std::exception& e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
	std::cout << "\n\n\n"<< std::endl;
    try
	{
        Bureaucrat c("Charlie", 100);
        std::cout << c << std::endl;
        c.increment();
        std::cout << "After increment: " << c << std::endl;
        c.decrement();
        std::cout << "After decrement: " << c << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
