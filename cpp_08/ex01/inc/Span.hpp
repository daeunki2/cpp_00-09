/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:29:11 by daeunki2          #+#    #+#             */
/*   Updated: 2025/10/06 13:12:15 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>//cout cin
#include <vector>//vector
#include <algorithm>//sort, min_element, max_element
#include <stdexcept>//error
#include <climits>//int_max 
#include <cmath>  // std::abs()


class Span
{
    private:
        std::vector<int> arr;
        unsigned int MaxSize;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        ~Span();
        Span& operator=(const Span& other);

    // ----------------- 핵심 기능 -----------------
    void addNumber(int number);    
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const; 
	template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
        unsigned int count = std::distance(begin, end);
        if (this->arr.size() + count > this->MaxSize)
        {
            throw ErrorException("addRange failed: The range exceeds Span's MaxSize.");
        }

        for (Iterator it = begin; it != end; ++it)
        {
            this->addNumber(*it);
        }
    }    void printAll() const; 

    class ErrorException : public std::runtime_error
    {
    public:
        // std::runtime_error는 생성자에서 메시지를 받습니다.
        explicit ErrorException(const std::string& message);
    };
};


#endif
