/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:09:54 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/11 17:04:51 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//constructor
Intern::Intern()
{
	
};
Intern::Intern(const Intern& src)
{
	(void)src;
};
//destructor
Intern::~Intern()
{
	
};
	
//Copy assignment operator
Intern& Intern::operator=(const Intern& src)
{
	(void)src;
    return *this;
}

//ststic for using function pointer
static AForm	*make_President(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*make_Robot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*make_Shrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

// Public Methods
AForm	*Intern::makeForm(const std::string form_to_create, const std::string target_for_form)
{
	AForm *(*all_forms[])(const std::string target) = 
	{
		&make_President,
		&make_Robot,
		&make_Shrubbery
	};
	
	std::string forms[] =
	{
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm"
	};

	for (int i = 0; i < 3; i++)
	{
		if (form_to_create == forms[i])
		{
			std::cout << "Intern creates " << form_to_create << " now" << std::endl;
			return (all_forms[i](target_for_form));
		}
	}

	std::cout << "\033[33mIntern can not create a form called " << form_to_create << "\033[0m" << std::endl;
	return (NULL);
}


