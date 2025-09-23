/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:42:03 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/23 21:48:08 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>      // rand(), srand()
#include <ctime>        // time()
#include "Span.hpp"

int main()
{
    try {
        // 기본 테스트
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

		sp.printAll();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;

        // 예외 테스트 (초과 추가)
        try
		{
            sp.addNumber(42);
        } catch (const Span::ErrorException& e) {
            std::cerr << "[Expected Exception] " << e.what() << std::endl;
        }

        // 대량 테스트
        Span bigSpan(10000);
        srand(static_cast<unsigned int>(time(NULL)));  // 랜덤 시드

        for (int i = 0; i < 100; ++i) {
            bigSpan.addNumber(rand());  // 0 ~ RAND_MAX 범위
        }

        std::cout << "Big span test:" << std::endl;
		bigSpan.printAll();
        std::cout << "  Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "  Longest span:  " << bigSpan.longestSpan() << std::endl;

    }
	catch (const std::exception& e)
	{
        std::cerr << "[Unhandled Exception] " << e.what() << std::endl;
    }

    return 0;
}
