/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:19:41 by daeunki2          #+#    #+#             */
/*   Updated: 2025/10/07 14:57:02 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
    
}

RPN::RPN(std::string argv)
:input(argv)
{
    
}

RPN::~RPN()
{
    
}
RPN::RPN(RPN& other)
{
    input = other.input;
    operand_stack = other.operand_stack;
}
RPN& RPN::operator=(RPN& other)
{
    if (this != &other)
    {
        input = other.input;
        operand_stack = other.operand_stack;
    }
    return (*this);
}

//check and set stacks

static bool is_valid_operand(const std::string& token)
{
    try
    {
        double num = std::stod(token);
        return num < 10; 
    }
    catch (const std::invalid_argument&)
    {
        return false;
    }
    catch (const std::out_of_range&)
    {
        return true;
    }
}

static bool is_operator(const std::string& token)
{
    if (token == "+" || token == "-" || token == "/" || token == "*")
        return true;
    return false;
}



// calculate logic
void RPN::calculate()
{
    std::stringstream ss(this->input);
    std::string token;

    double first = 0;
    double second = 0;
    int 	count = 0;
    while (ss >> token)
    {
        if (is_valid_operand(token)) 
        {
            operand_stack.push(std::stod(token));
			count++;
        }
        else if (is_operator(token))
        {
            if (operand_stack.size() < 2)
            {
                std::cerr << "Error: Not enough operands." << std::endl;
                return;
			}
            second = operand_stack.top();
            operand_stack.pop();
            first = operand_stack.top();
            operand_stack.pop();
            if (token == "+")
                operand_stack.push(first + second);
            else if (token == "-")
                operand_stack.push(first - second);
            else if (token == "*")
                operand_stack.push(first * second);
            else if (token == "/")
            {
                if (second == 0) // 0으로 나누기 오류 처리
                {
                    std::cerr << "Error: Division by zero." << std::endl;
                    return;
                }
                operand_stack.push(first / second);
            }
        }
        else
        {
            std::cerr << "Error: Unknown token or invalid operand format." << std::endl;
            return;
        }
    }

    if (operand_stack.size() == 1 && count >= 2)
    {
        std::cout << operand_stack.top() << std::endl;
    }
    else
    {
        std::cerr << "Error: Invalid expression structure (missing operators or operands)." << std::endl;
    }
}
