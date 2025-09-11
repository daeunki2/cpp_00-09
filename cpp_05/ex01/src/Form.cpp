/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:02:30 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/11 10:58:30 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

//constructor
Form::Form()//default constructor
: name("default"), is_signed(false), grade_to_sign(100), grade_to_excute(80)
{
	//std::cout << "default constructor" << std::endl;
};

Form::Form(std::string input, int ToSign, int ToExcute)//constructor with name and grade
: name(input), is_signed(false), grade_to_sign(ToSign), grade_to_excute(ToExcute)
{
	if (ToSign < 1 || ToExcute < 1) 
		throw GradeTooHighException();
    if (ToSign > 150 || ToExcute > 150)
		throw GradeTooLowException();
    //std::cout << "Constructor with parameters called" << std::endl;
	
};

Form::Form(const Form& src) //Copy constructor
:name(src.name), is_signed(src.is_signed),grade_to_sign(src.grade_to_sign), grade_to_excute(src.grade_to_excute)
{
	//std::cout << "copy constructor" << std::endl;
};



//Destructor
Form::~Form()
{
	//std::cout << "default destructor" << std::endl;
};



//Copy assignment operator
Form& Form::operator=(const Form& src)
{
    if (&src != this)
	{
        this->is_signed = src.is_signed;
	}	//std::cout << "Copy assignment operator" << std::endl;
    return *this;
};


//getter
std::string	Form::getName() const
{
	return(this->name);	
};

bool	Form::getsigned() const
{
	return(this->is_signed);
};

int		Form::getGradetoSign() const
{
	return(this->grade_to_sign);
};

int		Form::getGradetoExcute() const
{
	return(this->grade_to_excute);
};



//member function
void Form::beSigned(const Bureaucrat &mr)
{
	if (mr.getGrade() > this->grade_to_sign) throw GradeTooLowException();
	if(this->is_signed == true) throw FormCondition();
	this->is_signed = true;	
}




//exception
const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

const char *Form::FormCondition::what(void) const throw()
{
	return ("Form is already signed by some other officer");
};



//operator
std::ostream& operator<<(std::ostream& os, const Form& b)
{
    os << "Form " << b.getName()
       << ", signed: " << (b.getsigned() ? "true" : "false")
       << ", gradeToSign: " << b.getGradetoSign()
       << ", gradeToExecute: " << b.getGradetoExcute();
    return os;
}
