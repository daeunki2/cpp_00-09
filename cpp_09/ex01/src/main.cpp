/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:42:03 by daeunki2          #+#    #+#             */
/*   Updated: 2025/10/07 14:50:25 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

// 프로그램 이름: RPN
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "Usage: ./RPN \"<RPN expression>\"" << std::endl;
        return (EXIT_FAILURE);
    }
    try
    {
        RPN calculator(argv[1]);
        calculator.calculate();
    }
    catch (const std::exception& e)
    {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
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