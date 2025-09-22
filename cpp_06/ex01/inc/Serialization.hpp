/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:23:45 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/21 17:43:09 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream> //cout, cin
#include <string> //string

typedef struct Data
{
    int         id_number;
    std::string name;
} Data;

class 	Serialization
{
	private :
	Serialization();//constructor
	Serialization(const Serialization &other);//copy constructor
	Serialization &operator=(const Serialization &other);//copy assignment operator
	~Serialization();//destructor
	
	public :
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif