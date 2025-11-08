/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:19:41 by daeunki2          #+#    #+#             */
/*   Updated: 2025/11/08 15:45:25 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/******************************************************************************/
/*                        	Orthodox Canonical Form                           */
/******************************************************************************/


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
RPN::RPN(const RPN& other)
:input(other.input), operand_stack(other.operand_stack)
{
    
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        input = other.input;
        operand_stack = other.operand_stack;
    }
    return (*this);
}


/******************************************************************************/
/*                        	         Helper                                   */
/******************************************************************************/


static bool is_operator(const std::string& token)
{
    if (token.size() == 1 && (token == "+" || token == "-" || token == "/" || token == "*"))
        return true;
        
    if (token.size() == 1 && token[0] >= '0' && token[0] <= '9')
        return false;
        
    if (token.size() > 1 && (token.find_first_not_of("0123456789") == std::string::npos))
    {
        throw ::RPN_error("Operand must be a single digit integer (0-9)", ::RPN_error::LOGIC);
    }
    throw ::RPN_error("Unrecognized token: " + token, ::RPN_error::PARSE);
}

/******************************************************************************/
/*                        store and calcul                                   */
/******************************************************************************/

void RPN::calculate()
{
    std::stringstream ss(this->input);
    std::string token;

    double first = 0;
    double second = 0;

    while (ss >> token)
    {
        if (is_operator(token))
        {
            if (operand_stack.size() < 2)
            {
                throw ::RPN_error("Not enough operands for operator '" + token + "'", ::RPN_error::LOGIC);
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
                if (second == 0) 
                {
                    throw ::RPN_error("Cannot divide by zero", ::RPN_error::LOGIC);
                }
                operand_stack.push(first / second);
            }
        }
        else
        {
            operand_stack.push(static_cast<double>(token[0] - '0')); 
        }
    }

    if (operand_stack.size() == 1)
    {
        std::cout << operand_stack.top() << std::endl;
    }
    else
    {
        throw ::RPN_error("Invalid expression structure (too many operands or missing operators)", ::RPN_error::LOGIC);
    }
}