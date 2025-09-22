/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:29:59 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/21 22:09:25 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

template<typename T>
void print(T &str)
{
	std::cout << str << " ";
}

template<typename T>
void plus_one(T &num)
{
	num = num + 1;
}