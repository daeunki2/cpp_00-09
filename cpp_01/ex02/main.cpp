/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:13:38 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/24 04:24:09 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // cout, cin
#include <string> // string

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Let's print adress" << std::endl;
	std::cout << "The address of str : " << &str << std::endl;
	std::cout << "The address held by PTR : " << stringPTR << std::endl;
	std::cout << "The adress of PTR itself : " << &stringPTR << std::endl;
	std::cout << "\nThe address held by REF : " << &stringREF << std::endl;
	std::cout << "Address of REF itself    : " << &stringREF << std::endl;
	
	std::cout << "\n\nLet's print value" << std::endl;
	std::cout << "Value of str  : " << str << std::endl;
	std::cout << "Value pointed by PTR: " << *stringPTR << std::endl;
	std::cout << "Value of REF : " << stringREF << std::endl;

	return 0;
	
}