/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:47:25 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/31 23:00:30 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "AAnimal default constructor call\n";
}

AAnimal::AAnimal(const std::string &input) : type(input)
{
    std::cout << "AAnimal parameterized constructor call\n";
}

AAnimal::AAnimal(const AAnimal &src) : type(src.type)
{
    std::cout << "AAnimal copy constructor call\n";
}

AAnimal& AAnimal::operator=(const AAnimal &src)
{
    if (this != &src)
        type = src.type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor call\n";
}

std::string AAnimal::getType() const
{
    return type;
}
