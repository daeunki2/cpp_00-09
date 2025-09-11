/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:41:48 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/11 15:04:00 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    srand(time(NULL)); // 랜덤 시드 초기화 (RobotomyRequestForm 용)

    try
    {
        std::cout << "\n--- officer bob and tom ---\n";

        Bureaucrat bob("Bob", 1); // 제일 높은 등급
        Bureaucrat tom("Tom", 150); // 제일 낮은 등급

        std::cout << bob << std::endl;
        std::cout << tom << std::endl;

        std::cout << "\n--- paper works ---\n";
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << shrub << std::endl;
        std::cout << robo << std::endl;
        std::cout << pardon << std::endl;
        
        std::cout << "\n--- Signing Forms ---\n";
        tom.signForm(shrub); // error : too low
        bob.signForm(shrub);
        bob.signForm(pardon);
        bob.signForm(pardon);// error : already signed

        std::cout << "\n--- Executing Forms ---\n";
        bob.executeForm(shrub);
        bob.executeForm(robo); // error : not signed
        bob.signForm(robo);
        bob.executeForm(robo);
        bob.executeForm(pardon);

        std::cout << "\n--- Low grade bureaucrat trying ---\n";
        tom.executeForm(shrub); // 실패 예외 발생
    }
    catch (const std::exception &e)
    {
        std::cerr << "\033[31m" << "\nException caught: " << e.what() << "\033[0m" << std::endl;
    }

    return 0;
}
 

