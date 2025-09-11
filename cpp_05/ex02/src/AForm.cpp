/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:13:15 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/11 14:48:57 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"

//constructor
AForm::AForm()//default constructor
: name("default"), is_signed(false), grade_to_sign(100), grade_to_excute(80)
{
	//std::cout << "default constructor" << std::endl;
};

AForm::AForm(std::string input, int ToSign, int ToExcute)//constructor with name and grade
: name(input), is_signed(false), grade_to_sign(ToSign), grade_to_excute(ToExcute)
{
	if (ToSign < 1 || ToExcute < 1) 
		throw GradeTooHighException();
    if (ToSign > 150 || ToExcute > 150)
		throw GradeTooLowException();
    //std::cout << "Constructor with parameters called" << std::endl;
	
};

AForm::AForm(const AForm& src) //Copy constructor
:name(src.name), is_signed(src.is_signed),grade_to_sign(src.grade_to_sign), grade_to_excute(src.grade_to_excute)
{
	//std::cout << "copy constructor" << std::endl;
};



//Destructor
AForm::~AForm()
{
	//std::cout << "default destructor" << std::endl;
};



//Copy assignment operator
AForm& AForm::operator=(const AForm& src)
{
    if (&src != this)
	{
        this->is_signed = src.is_signed;
	}	//std::cout << "Copy assignment operator" << std::endl;
    return *this;
};


//getter
std::string	AForm::getName() const
{
	return(this->name);	
};

bool	AForm::getsigned() const
{
	return(this->is_signed);
};

int		AForm::getGradetoSign() const
{
	return(this->grade_to_sign);
};

int		AForm::getGradetoExcute() const
{
	return(this->grade_to_excute);
};



//member function
void AForm::beSigned(const Bureaucrat &mr)
{
	if (mr.getGrade() > this->grade_to_sign) throw GradeTooLowException();
	if(this->is_signed == true) throw AFormisalreadySigned();
	this->is_signed = true;	
}

void AForm::execute(const Bureaucrat & executor) const
{
	if (executor.getGrade() > this->grade_to_excute)
		throw GradeTooLowException();
	if (is_signed == false)
		throw AFormisNotSigned();
	executeAction();
}


//exception
const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

const char *AForm::AFormisalreadySigned::what(void) const throw()
{
	return ("AForm is already signed by some other officer");
};

const char *AForm::AFormisNotSigned::what(void) const throw()
{
	return ("AForm is not singed");
};



//operator
std::ostream& operator<<(std::ostream& os, const AForm& b)
{
    os << "AForm " << b.getName()
       << ", signed: " << (b.getsigned() ? "true" : "false")
       << ", gradeToSign: " << b.getGradetoSign()
       << ", gradeToExecute: " << b.getGradetoExcute();
    return os;
}
