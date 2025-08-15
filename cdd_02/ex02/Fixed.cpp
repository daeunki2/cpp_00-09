/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:36:39 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/15 01:28:11 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


const int Fixed::fractional_bits = 8;

Fixed::Fixed()
{
    value = 0;
//    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int init)
{
    this->value = init << fractional_bits;
//    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float init)
{
    value = round(init * (1 << fractional_bits));
//    std::cout << "Float constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& original)
{
//    std::cout << "Copy constructor called" << std::endl;
    *this = original;
}
Fixed::~Fixed()
{
 //   std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

float   Fixed::toFloat(void) const
{
    return((float)this->value / (1 << fractional_bits));
}

int     Fixed::toInt(void) const
{
    return(this->value >> fractional_bits);
}

Fixed& Fixed::operator = (const Fixed& source)
{
 //   std::cout << "Copy assignment operator called" << std::endl;
    if (this != &source)
    {
        this->value = source.getRawBits();
    }
    return (*this);
}

Fixed Fixed::operator+(Fixed const &ref) const
{
    Fixed ret(this->toFloat() + ref.toFloat());
    return ret;
}

Fixed Fixed::operator-(Fixed const &ref) const
{
    Fixed ret(this->toFloat() - ref.toFloat());
    return ret;
}

Fixed Fixed::operator*(Fixed const &ref) const
{
    Fixed ret(this->toFloat() * ref.toFloat());
    return ret;
}

Fixed Fixed::operator/(Fixed const &ref) const
{
    Fixed ret(this->toFloat() / ref.toFloat());
    return ret;
}



bool	Fixed::operator>(Fixed const &ref) const
{
    return (this->toFloat() > ref.toFloat());
}

bool	Fixed::operator>=(Fixed const &ref) const
{
    return (this->toFloat() >= ref.toFloat());
}

bool	Fixed::operator<(Fixed const &ref) const
{
    return (this->toFloat() < ref.toFloat());
}

bool	Fixed::operator<=(Fixed const &ref) const
{
    return (this->toFloat() <= ref.toFloat());
}

bool	Fixed::operator==(Fixed const &ref) const
{
    return (this->toFloat() == ref.toFloat());
}

bool	Fixed::operator!=(Fixed const &ref) const
{
    return (this->toFloat() != ref.toFloat());
}



std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat(); 
    return os;
}



Fixed&   Fixed::operator++(void)
{
    this->value++;
    return (*this);
}
Fixed   Fixed::operator++(int)
{
    Fixed   temp(*this);
    this->value++;
    return (temp);
}
Fixed&   Fixed::operator--(void)
{
    this->value--;
    return (*this);
}
Fixed   Fixed::operator--(int)
{
    Fixed   temp(*this);
    this->value--;
    return (temp);
}


Fixed&   Fixed::min (Fixed& a, Fixed& b)
{
    if (a >= b)
        return (b);
    else
        return(a);
}
const Fixed&   Fixed::min (const Fixed& a, const Fixed& b)
{
    if (a >= b)
        return (b);
    else
        return(a);
}
Fixed&   Fixed::max (Fixed& a, Fixed& b)
{
    if (a <= b)
        return (b);
    else
        return(a);
}
const Fixed&   Fixed::max (const Fixed& a, const Fixed& b)
{
    if (a <= b)
        return (b);
    else
        return(a);
}