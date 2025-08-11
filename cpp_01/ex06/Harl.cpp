/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:35:40 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/11 21:51:36 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
    
}

Harl::~Harl(void)
{
    
}
	
void Harl::debug( void ) 
{
    std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
}
	
void Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did" << std::endl;
    std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;	


}
	
void Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*function_pointer[])() =
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string complains[] = 
    {
        "DEBUG", 
        "INFO", 
        "WARNING", 
        "ERROR"
    };

	int depth = 0;
    
	for (; depth < 4; depth++)
	{
		if (complains[depth] == level)
			break ;
	}
    
	switch(depth)
	{
		case(0):
            (this->*function_pointer[0])();
		case(1):
			(this->*function_pointer[1])();
		case(2):
			(this->*function_pointer[2])();
		case(3):
			(this->*function_pointer[3])();
			break;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

