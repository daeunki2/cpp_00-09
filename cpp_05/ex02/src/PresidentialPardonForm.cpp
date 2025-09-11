/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:13:22 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/11 14:49:35 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructor
PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), target("default_target")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target_name)
: AForm("PresidentialPardonForm", 25, 5), target(target_name)
{
}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
: AForm(src), target(src.target)
{
}

// Copy Assignment Operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
    if (this != &src)
    {
        AForm::operator=(src); 
        target = src.target;
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

// Execute Action
void PresidentialPardonForm::executeAction() const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
