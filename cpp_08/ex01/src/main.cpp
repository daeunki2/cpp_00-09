/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:42:03 by daeunki2          #+#    #+#             */
/*   Updated: 2025/10/06 13:16:21 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <exception>
#include "Span.hpp"

int main()
{
    try {
        // Span 객체를 크기 5로 생성
        Span sp(50);
        
        // addNumber() 사용하여 숫자 추가
        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);
        sp.addNumber(40);
        sp.addNumber(50);

        // Span에 숫자가 다 채워졌으므로 addNumber가 두 번 실패할 것
        try {
            sp.addNumber(60);  // 여기에선 예외 발생
        } catch (const Span::ErrorException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // 출력
        std::cout << "All numbers in Span: ";
        sp.printAll();

        // shortestSpan과 longestSpan 테스트
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        // addRange() 사용해서 숫자 범위 추가
        std::vector<int> more_numbers;
        more_numbers.push_back(60);
        more_numbers.push_back(70);
        more_numbers.push_back(80);

        sp.addRange(more_numbers.begin(), more_numbers.end());  // 범위 추가

        std::cout << "After adding range of numbers: ";
        sp.printAll();

        // 새로운 shortestSpan과 longestSpan 계산
        std::cout << "New Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "New Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (const Span::ErrorException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
