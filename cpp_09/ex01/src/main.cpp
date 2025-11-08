/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:42:03 by daeunki2          #+#    #+#             */
/*   Updated: 2025/11/08 15:45:47 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"
#include "Error.hpp"
#include <iostream>
#include <cstdlib> // EXIT_FAILURE/EXIT_SUCCESS를 위해 추가

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        try {
            throw ::RPN_error("Usage: ./RPN 1_string_to_calcul", ::RPN_error::DEFAULT);
        } catch (const ::RPN_error& e) {
            e.print();
        }
        return (EXIT_FAILURE);
    }
    
    try
    {
        RPN calculator(argv[1]);
        calculator.calculate();
    }
    catch (const ::RPN_error& e) // RPN_error를 명시적으로 잡습니다.
    {
        e.print(); // RPN_error::print()를 사용하여 색깔 있는 에러 메시지 출력
        return (EXIT_FAILURE);
    }
    catch (const std::exception& e) // 그 외의 예상치 못한 표준 예외 처리
    {
        std::cerr << RED << "[Error] Unexpected standard exception: " << e.what() << RESET << std::endl;
        return (EXIT_FAILURE);
    }
    
    return (EXIT_SUCCESS);
}

// 컴파일 및 실행 예시 (Linux/macOS):
// g++ RPN.cpp main.cpp -o RPN
// ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"    // 출력: 42
// ./RPN "1 2 3 *"                      // 출력: Error: Invalid expression structure...
// ./RPN "10 2 +"                       // 출력: Error: Unknown token or invalid operand format: 10
// ./RPN "1 0 /"                        // 출력: Error: Division by zero.