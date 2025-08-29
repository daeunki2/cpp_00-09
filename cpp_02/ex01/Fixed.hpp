/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:28:40 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/25 14:21:26 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream> // cout, cin
#include <cmath> //round

class Fixed
{
private:
    int                 value;
    static const int    fractional_bits;

public:
    Fixed();// Default constructor
    Fixed(const int init);
    Fixed(const float init);
    Fixed(const Fixed& other);//Copy constructo
    Fixed& operator=(const Fixed& other);//Copy assignment operator
    ~Fixed();//Destructor
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
