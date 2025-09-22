/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:29:56 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/21 22:11:56 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *array, size_t length, void (*func)(T &))
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}
template<typename T>

void iter(T *array, size_t length, void (*func)(T const &))
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

#endif