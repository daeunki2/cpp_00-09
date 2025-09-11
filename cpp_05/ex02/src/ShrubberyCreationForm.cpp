/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:13:26 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/11 13:19:25 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), target("default_target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target_name)
: AForm("ShrubberyCreationForm", 145, 137), target(target_name)
{
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
: AForm(src), target(src.target)
{
}

// Copy Assignment Operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
    if (this != &src)
    {
        AForm::operator=(src); 
        target = src.target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

// Execute Action
void ShrubberyCreationForm::executeAction() const
{
    std::ofstream ofs(target + "_shrubbery");
    if (!ofs)
        throw file_problems();

    ofs <<
    "       _-_\n"
    "    /~~   ~~\\\n"
    " /~~         ~~\\\n"
    "{               }\n"
    " \\  _-     -_  /\n"
    "   ~  \\ //  ~\n"
    "_- -   | | _- _\n"
    "  _ -  | |   -_\n"
    "      // \\\\" << std::endl;

    ofs.close();
    std::cout << "Shrubbery created at " << target << "_shrubbery" << std::endl;
}


const char *ShrubberyCreationForm::file_problems::what(void) const throw()
{
	return ("File problem occurred in ShrubberyCreationForm");
};