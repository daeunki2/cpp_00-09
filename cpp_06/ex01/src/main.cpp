/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:41:25 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/21 17:41:55 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main()
{
    Data myData;
    myData.id_number = 42;
    myData.name = "Hello, World!";
    std::cout << "Original Data address: " << &myData << std::endl;

    uintptr_t serializedValue = Serialization::serialize(&myData);
    std::cout << "Serialized value:      " << serializedValue << std::endl;

    Data* deserializedPtr = Serialization::deserialize(serializedValue);
    std::cout << "Deserialized address:  " << deserializedPtr << std::endl;

    if (&myData == deserializedPtr)
    {
        std::cout << "\nComparison successful! The pointers are equal." << std::endl;
        std::cout << "Data members check: " << std::endl;
        std::cout << "ID: " << deserializedPtr->id_number << std::endl;
        std::cout << "Name: " << deserializedPtr->name << std::endl;
    }
    else
    {
        std::cout << "\nComparison failed! The pointers are not equal." << std::endl;
    }

    return 0;
}