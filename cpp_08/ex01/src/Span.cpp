/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:44:53 by daeunki2          #+#    #+#             */
/*   Updated: 2025/10/06 13:11:29 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
: arr(), MaxSize(0) 
{
}

Span::Span(unsigned int N)
: arr(), MaxSize(N) 
{
}

Span::Span(const Span& other)
: arr(other.arr), MaxSize(other.MaxSize)
{
}

Span::~Span()
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->arr = other.arr;
        this->MaxSize = other.MaxSize; 
    }
    return *this;
}

    // ----------------- 핵심 기능 -----------------
void Span::addNumber(int number)
{
    if (this->MaxSize == 0)
    {
        throw ErrorException("addNumber failed: MaxSize is 0, cannot add numbers.");
    }

    if (this->arr.size() >= this->MaxSize)
    {
        throw ErrorException("addNumber failed: Span is already full.");
    }
    this->arr.push_back(number);
}
unsigned int Span::shortestSpan() const
{
    if (arr.size() < 2)
    {
        throw std::logic_error("Not enough numbers to calculate shortest span.");
    }

    std::vector<int> sorted_arr = arr;
    std::sort(sorted_arr.begin(), sorted_arr.end());

    unsigned int min_span = std::numeric_limits<unsigned int>::max();

    for (size_t i = 0; i < sorted_arr.size() - 1; ++i)
    {
        unsigned int current_span = std::abs(sorted_arr[i + 1] - sorted_arr[i]);
        if (current_span < min_span)
        {
            min_span = current_span;
        }
    }

    return min_span;
}

unsigned int Span::longestSpan() const
{
    if (this->arr.size() < 2)
    {
        throw ErrorException("longestSpan failed: Need at least 2 numbers to calculate span.");
    }
    
    int min_val = *std::min_element(this->arr.begin(), this->arr.end());
    int max_val = *std::max_element(this->arr.begin(), this->arr.end());

    return static_cast<unsigned int>(std::abs(max_val - min_val));
}

void Span::printAll() const
{
    unsigned int len = this->arr.size();
    for (unsigned int i = 0; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


Span::ErrorException::ErrorException(const std::string& message)
: std::runtime_error(message) 
{
}