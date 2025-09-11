/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:41:48 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/11 17:07:51 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Intern kim;

    std::cout << "\n--- Intern kim starts making forms ---\n";

    AForm* form1 = nullptr;
    AForm* form2 = nullptr;
    AForm* form3 = nullptr;

    try
    {
        form1 = kim.makeForm("PresidentialPardonForm", "Alice");
        form2 = kim.makeForm("RobotomyRequestForm", "Bob");
        form3 = kim.makeForm("ShrubberyCreationForm", "Garden");
    }
    catch (const std::exception &e)
    {
        std::cerr << "\033[31mException caught while creating forms: " << e.what() << "\033[0m" << std::endl;
    }

    try
    {
        AForm* form4 = kim.makeForm("UnknownForm", "Nobody");
        delete form4; // makeForm이 정상적으로 반환하면 삭제
    }
    catch (const std::exception &e)
    {
        std::cerr << "\033[31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    try
    {
        std::cout << "\n--- Bureaucrats Bob and Tom ---\n";

        Bureaucrat bob("Bob", 1);   // 최고 등급
        Bureaucrat tom("Tom", 150); // 최저 등급

        std::cout << bob << std::endl;
        std::cout << tom << std::endl;
        
        std::cout << "\n--- papers ---\n";
        std::cout << *form1 << std::endl;
        std::cout << *form2 << std::endl;
        std::cout << *form3 << std::endl;

        std::cout << "\n--- Signing Forms ---\n";
        tom.signForm(*form3); // too low, 예외 발생
        bob.signForm(*form3);
        bob.signForm(*form1);
        bob.signForm(*form1); // 이미 서명됨, 예외 발생

        std::cout << "\n--- Executing Forms ---\n";
        bob.executeForm(*form3);
        bob.executeForm(*form2); // 아직 서명 안 됨, 예외 발생
        bob.signForm(*form2);
        bob.executeForm(*form2);
        bob.executeForm(*form1);

        std::cout << "\n--- Low grade bureaucrat trying to execute ---\n";
        tom.executeForm(*form3); // 실패 예외 발생
    }
    catch (const std::exception &e)
    {
        std::cerr << "\033[31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    // 정리
    delete form1;
    delete form2;
    delete form3;

    return 0;
}
