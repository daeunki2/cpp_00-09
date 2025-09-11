/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:13:30 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/11 14:44:10 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructor
RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), target("default_target")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target_name)
: AForm("RobotomyRequestForm", 72, 45), target(target_name)
{
}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
: AForm(src), target(src.target)
{
}

// Copy Assignment Operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
    if (this != &src)
    {
        AForm::operator=(src); 
        target = src.target;
    }
    return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

// Execute Action
void RobotomyRequestForm::executeAction() const
{
    std::cout << "Bzzzzzz... drilling noises..." << std::endl;

    if (rand() % 2 == 0)
        std::cout << "🤖🤖🤖🤖" << this->target << " has been robotomized successfully!" << std::endl;
    else
        throw RobotomyFailedException();
}

const char *RobotomyRequestForm::RobotomyFailedException::what() const throw()
{
    return ("Robotomy failed.....");
}
