/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:13:01 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/11 14:50:04 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include <cstdlib>  // rand, srand
#include "AForm.hpp" //mother class

class RobotomyRequestForm : public AForm
{
private:
    std::string target;

public:
    //Constructor
	RobotomyRequestForm();
    RobotomyRequestForm(std::string target_name);
    //copy Constructor
    RobotomyRequestForm(const RobotomyRequestForm& src);
	//Copy assignment operator
    RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
    //Destructor
    ~RobotomyRequestForm();
    
	//special action
    void executeAction() const;
	
	//error control
	class RobotomyFailedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif
