/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:28:40 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/25 14:20:59 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream> // cout, cin

class Fixed
{
private:
    int                 int_container;
    static const int    bite_container;

public:
    Fixed(); //Default constructor
    Fixed(const Fixed& other); //Copy constructor
    Fixed& operator=(const Fixed& other);//Copy assignment operator
    ~Fixed();//Destructor
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif

