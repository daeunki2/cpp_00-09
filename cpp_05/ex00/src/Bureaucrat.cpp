/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:16:54 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/11 11:09:07 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//constructor
Bureaucrat::Bureaucrat()//default constructor
: name("default"), grade(150)
{
	//std::cout << "default constructor" << std::endl;
};

Bureaucrat::Bureaucrat(std::string input, int g)//constructor with name and grade
: name(input)
{
	if (g < 1) throw GradeTooHighException();
    if (g > 150) throw GradeTooLowException();
    grade = g;
    //std::cout << "Constructor with parameters called" << std::endl;
	
};

Bureaucrat::Bureaucrat(const Bureaucrat& src) //Copy constructor
:name(src.name), grade(src.grade)
{
	//std::cout << "copy constructor" << std::endl;
};



//Destructor
Bureaucrat::~Bureaucrat()
{
	//std::cout << "default destructor" << std::endl;
};



//Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    if (&src != this)
        this->grade = src.grade;
    //std::cout << "Copy assignment operator" << std::endl;
    return *this;
};


//getter
std::string	Bureaucrat::getName() const
{
	return(this->name);
};

int		Bureaucrat::getGrade() const
{
	return(this->grade);
};



//member function
void Bureaucrat::increment()
{
	if (grade <= 1) throw GradeTooHighException();
    grade--;
	std::cout << "Promotion! Bureaucrat " << this->getGrade() << "is now grade" << this->getGrade() << std::endl;
};

void Bureaucrat::decrement()
{
	if (grade >= 150) throw GradeTooLowException();
    grade++;
	std::cout << "Oops! Bureaucrat " << this->getName()<< "is now grade" << this->getGrade() << std::endl;
};



//exception
const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};



//operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
};