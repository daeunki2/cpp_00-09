/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:13:05 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/11 14:48:10 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream> //file
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;

public:
    //Constructor
	ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target_name);
    //copy Constructor
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
	//Copy assignment operator
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
    //Destructor
    ~ShrubberyCreationForm();
    
	//special action
    void executeAction() const;
	
	//error control
	class file_problems : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif
