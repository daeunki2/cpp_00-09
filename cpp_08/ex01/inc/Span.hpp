/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:29:11 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/23 21:46:03 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/*
Span 클래스 개발

최대 N개의 정수를 저장할 수 있는 Span 클래스를 개발하세요.
N은 unsigned int 변수이며, 생성자에 유일하게 전달되는 매개변수입니다.

이 클래스에는 단일 숫자를 Span에 추가하는 데 사용되는 addNumber()라는 멤버 함수가 있어야 합니다.
이미 N개의 요소가 저장되어 있는 경우 새로운 요소를 추가하려고 하면 예외를 던져야 합니다.

그 다음으로, shortestSpan()과 longestSpan()이라는 두 개의 멤버 함수를 구현하세요.
이 함수들은 각각 저장된 모든 숫자들 간의 가장 짧은 거리(또는 span) 와 가장 긴 거리(또는 span) 를 계산하여 반환합니다.

만약 저장된 숫자가 없거나, 단 하나만 저장된 경우에는 span을 구할 수 없습니다.
이 경우에도 예외를 던져야 합니다.

물론, 테스트 코드는 직접 작성해야 하며, 아래 제공된 테스트보다 더 철저해야 합니다.
최소한 10,000개 이상의 숫자로 Span을 테스트하세요. 더 많은 수의 테스트가 권장됩니다.
*/
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>//cout cin
#include <vector>//vector
#include <algorithm>//sort, min_element, max_element
#include <stdexcept>
#include <climits>//int_max

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

    void addNumber(int number);
    unsigned int shortestSpan();
    unsigned int longestSpan();

	void printAll() const;

	//basic error class
    class ErrorException : public std::runtime_error
    {
    public:
        explicit ErrorException(const std::string& message);
    };
};

#endif
