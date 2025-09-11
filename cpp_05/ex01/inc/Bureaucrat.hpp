/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:16:50 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/10 17:12:51 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>//cin cout
#include <string>//string
#include <exception>//exception
#include "Form.hpp"

class Bureaucrat
{
	private :
	const std::string 	name;
	int 				grade;

	public :
	//cinstructor
	Bureaucrat();//default constructor
	Bureaucrat(std::string input, int g);//constructor with default constructor
	Bureaucrat(const Bureaucrat& src); //Copy constructor
	
	//destructor
	~Bureaucrat();//default Destructor
	
	//Copy assignment operator
	Bureaucrat& operator=(const Bureaucrat& src);
	
	//getter
	std::string	getName() const;
	int			getGrade() const;
	
	//member function
	void 		increment();
	void 		decrement();
	void 		signForm(Form &f);

	
	//exception
	class GradeTooLowException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif