/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:43:09 by daeunki2          #+#    #+#             */
/*   Updated: 2025/10/06 10:51:04 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // std::find를 사용하기 위해 필요
#include <stdexcept> // std::runtime_error 예외를 사용하기 위해 필요
#include <iostream>//cin, cout


template <typename T>
typename T::const_iterator easyfind(const T& container, int to_find)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), to_find);

    if (it == container.end())
    {
        throw std::runtime_error("Error: Value not found in the container.");
    }

    return it;
}

#endif