/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:28:15 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/21 19:28:31 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T& a, T& b) 
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

#endif