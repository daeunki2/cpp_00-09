/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:44:53 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/23 21:45:54 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
:arr(), MaxSize(1000)
{
    arr.reserve(MaxSize);
};

Span::Span(unsigned int N)
:arr(), MaxSize(N)
{
    arr.reserve(MaxSize);
}

Span::Span(const Span& other)
:  arr(other.arr), MaxSize(other.MaxSize)
{
	
};

Span::~Span()
{
	
};

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        MaxSize = other.MaxSize;
        arr = other.arr;
    }
    return *this;
};


void Span::addNumber(int number)
{
    if (arr.size() >= MaxSize)
        throw ErrorException("Span is full. Cannot add more numbers.");
    arr.push_back(number);
}

unsigned int Span::shortestSpan()
{
	if (arr.size() < 2)
		throw ErrorException("Span needs at least 2 numbers.");

	std::vector<int> sorted = arr;
	std::sort(sorted.begin(), sorted.end());

    unsigned int gap = UINT_MAX;

    for (size_t i = 1; i < sorted.size(); ++i)
    {
        unsigned int diff = sorted[i] - sorted[i - 1];
        if (diff < gap)
            gap = diff;
	}
	return (gap);
}

unsigned int Span::longestSpan()
{
	if (arr.size() < 2)
		throw ErrorException("Span needs at least 2 numbers.");

	int max = *std::max_element(arr.begin(), arr.end());
	int min = *std::min_element(arr.begin(), arr.end());

	return (max - min);
}

void Span::printAll() const
{
    std::cout << "Stored numbers (" << arr.size() << "/" << MaxSize << "): ";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i != arr.size() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}


Span::ErrorException::ErrorException(const std::string& message)
    : std::runtime_error(message)
{

};
