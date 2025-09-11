/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:02:34 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/11 10:56:26 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>//cin cout
#include <string>//string
#include <exception>//exception

class Bureaucrat;

class Form
{
	private :
	const std::string 	name;
	bool				is_signed;
	const int 			grade_to_sign;
	const int			grade_to_excute;
	
	public :
	//constructor
 	Form();//default constructor
 	Form(std::string input, int ToSign, int ToExcute);//constructor with default constructor
 	Form(const Form& src); //Copy constructor
	
	//destructor
	~Form();//default Destructor
	
	//Copy assignment operator
 	Form& operator=(const Form& src);
	
	//getter
	std::string	getName() const;
	bool	getsigned() const;
	int		getGradetoSign() const;
	int		getGradetoExcute() const;

	//member function
	void beSigned(const Bureaucrat &b);

	
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
	class FormCondition : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};
std::ostream& operator<<(std::ostream& os, const Form& b);

#endif