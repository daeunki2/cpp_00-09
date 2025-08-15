/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FIxed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:36:39 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/14 23:02:02 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bite_container = 8;

//생성자
Fixed::Fixed()
{
    int_container = 0;
    std::cout << "Default constructor called" << std::endl;
}
//복사생성자
Fixed::Fixed(const Fixed& original)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = original;
}
//소멸자
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
//복사 대입 연산자
Fixed& Fixed::operator=(const Fixed& source)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &source)
    {
        this->int_container = source.getRawBits();
    }
    return (*this);
}

//함수1
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->int_container);
}
//함수2
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->int_container = raw;
}
