/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:41:48 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/11 11:03:48 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 30);
        Bureaucrat bob("Bob", 101);

        std::cout << "----------officer---------" <<std::endl;
        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << "\n-----form-----" <<std::endl;
        Form taxForm("Tax Form", 50, 25);
        Form travelForm("Travel Form", 100, 50);

        std::cout << taxForm << std::endl;
        std::cout << travelForm << std::endl;

        std::cout << "\n-----strat job-----" <<std::endl;
        // Alice grade = 30, tax form grade = 50 
        alice.signForm(taxForm);
        
        // tax form is already signed
        alice.signForm(taxForm);

        // Bob grade 101, Tax Form grade = 50 
        bob.signForm(taxForm);

        // Bob grade 101 = Travel Form = 100
        bob.signForm(travelForm);

        bob.increment();
        // Bob grade 101 = Travel Form = 100
        bob.signForm(travelForm);

        std::cout << "\n-----resulte-----" <<std::endl;

        std::cout << taxForm << std::endl;
        std::cout << travelForm << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}
