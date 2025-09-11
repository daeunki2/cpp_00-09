/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:12:57 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/11 14:47:58 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string target;

public:
    //Constructor
	PresidentialPardonForm();
    PresidentialPardonForm(std::string target_name);
    //copy Constructor
    PresidentialPardonForm(const PresidentialPardonForm& src);
	//Copy assignment operator
    PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
    //Destructor
    ~PresidentialPardonForm();
    
	//special action
    void executeAction() const;
	
	
};

#endif
