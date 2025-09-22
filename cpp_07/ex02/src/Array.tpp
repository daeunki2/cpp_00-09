/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:48:41 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/21 23:00:01 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include "Array.hpp"
#include <exception>

template <typename T>
Array<T>::Array() : data(nullptr), size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), size(n)
{}

template <typename T>
Array<T>::Array(const Array& other) : data(nullptr), size(0)
{
    *this = other;
}

template <typename T>
Array<T>::~Array()
{
    delete[] data;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
	{
        delete[] data;
        size = other.size;
        data = new T[size];
        for (unsigned int i = 0; i < size; ++i)
		{
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= size)
	{
        throw std::exception();
    }
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= size) {
        throw std::exception();
    }
    return data[index];
}

template <typename T>
unsigned int Array<T>::getSize() const
{
    return size;
}