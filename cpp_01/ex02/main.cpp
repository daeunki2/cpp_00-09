/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:13:38 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/07 16:19:57 by daeunki2         ###   ########.fr       */
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
	std::cout << "the original str : " << &str << std::endl;
	std::cout << "the pointer of str : " << &stringPTR << std::endl;
	std::cout << "the referance of str : " << &stringREF << std::endl;
	
	std::cout << "Let's print value" << std::endl;
	std::cout << "the original str : " << str << std::endl;
	std::cout << "the pointer of str : " << *stringPTR << std::endl;
	std::cout << "the referance of str : " << stringREF << std::endl;

	return 0;
	
}