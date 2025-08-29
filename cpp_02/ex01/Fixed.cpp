/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:36:39 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/24 05:08:16 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


const int Fixed::fractional_bits = 8;

//생성자
Fixed::Fixed()
{
    value = 0;
    std::cout << "Default constructor called" << std::endl;
}
//정수형 생성자
Fixed::Fixed(const int init)
{
    this->value = init << fractional_bits;
    std::cout << "Int constructor called" << std::endl;
    /*
    42      [00000000 0000000 00000000 00101010]
    42 << 8 [00000000 0000000 00101010 00000000]
    */
}

Fixed::Fixed(const float init) //37.25
{
    value = round(init * (1 << fractional_bits)); //37.25 * 256
    std::cout << "Float constructor called" << std::endl;
	//like this you can store a value in a int
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
        this->value = source.getRawBits();
    }
    return (*this);
}

//함수1
int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}
//함수2
void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}
//함수3
float   Fixed::toFloat(void) const
{
    return((float)this->value / (1 << fractional_bits));
}
//함수4
int     Fixed::toInt(void) const
{
    return(this->value >> fractional_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat(); 
    return os;
}