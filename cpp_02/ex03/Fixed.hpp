/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:28:40 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/15 01:29:09 by daeunki2         ###   ########.fr       */
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
    //inti
    Fixed();
    Fixed(const int init);
    Fixed(const float init);
    Fixed(const Fixed& other);
    //destroy
    ~Fixed();
    //get,set
    int getRawBits(void) const;
    void setRawBits(int const raw);
    //convert
    float toFloat(void) const;
    int toInt(void) const;
    //overload
    Fixed& operator=(const Fixed& other);
    
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    
    bool	operator>(Fixed const &ref) const;
    bool	operator<(Fixed const &ref) const;
    bool	operator>=(Fixed const &ref) const;
    bool	operator<=(Fixed const &ref) const;
    bool	operator==(Fixed const &ref) const;
    bool	operator!=(Fixed const &ref) const;
    
    Fixed &operator ++ (void);
    Fixed operator ++ (int);
    Fixed &operator -- (void);
    Fixed operator -- (int);
    //compare
    static Fixed& min (Fixed& a, Fixed& b);
    static const Fixed& min (const Fixed& a, const Fixed& b); 
    static Fixed& max (Fixed& a, Fixed& b); 
    static const Fixed& max (const Fixed& a, const Fixed& b); 
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif