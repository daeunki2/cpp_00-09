/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:31:27 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/21 17:43:42 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

// ------------------------
// basic constructor destructor
// ------------------------
Serialization::Serialization()
{
	
};
Serialization::Serialization(const Serialization &other)
{
	(void)other;
}
Serialization& Serialization::operator=(const Serialization &other)
{
	(void)other;
	return *this;
}
Serialization::~Serialization()
{
	
}

uintptr_t	Serialization::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}
Data*	Serialization::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
