/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:12:53 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/11 12:11:41 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>//cin cout
#include <string>//string
#include <exception>//exception

class Bureaucrat;

class AForm
{
	private :
	const std::string 	name;
	bool				is_signed;
	const int 			grade_to_sign;
	const int			grade_to_excute;
	
	public :
	//constructor
 	AForm();//default constructor
 	AForm(std::string input, int ToSign, int ToExcute);//constructor with default constructor
 	AForm(const AForm& src); //Copy constructor
	
	//destructor
	virtual ~AForm();//default Destructor
	
	//Copy assignment operator
 	AForm& operator=(const AForm& src);
	
	//getter
	std::string	getName() const;
	bool	getsigned() const;
	int		getGradetoSign() const;
	int		getGradetoExcute() const;

	//member function
	void beSigned(const Bureaucrat &b);
	//excution
	virtual void executeAction() const = 0;
    void execute(const Bureaucrat & executor) const;

	
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
	
	class AFormisalreadySigned: public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	
	class AFormisNotSigned: public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};
std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif