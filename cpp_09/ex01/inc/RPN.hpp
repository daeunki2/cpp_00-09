/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:12:30 by daeunki2          #+#    #+#             */
/*   Updated: 2025/10/07 14:36:58 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
You must create a program with these constraints:
• Your program must take an inverted Polish mathematical expression as an argu- ment.
• The numbers used in this operation and passed as arguments will always be less than 10. 
 The calculation itself but also the result do not take into account this rule.
• Your program must process this expression and output the correct result on the standard output.
• If an error occurs during the execution of the program an error message should be displayed on the standard error.
• Your program must be able to handle operations with these tokens: "+ - / *".
*/

#ifndef RPN_HPP
#define RPN_HPP

#include <string> //string
#include <stack> //stack
#include <stdexcept> //exception
#include <iostream> //cin cout
#include <sstream> //sstream

class RPN
{
    private:
        std::string input;
        std::stack<double> operand_stack;  //number
    
    public:
        RPN();
        RPN(std::string argv);
        ~RPN();
        RPN(RPN& other);
        RPN& operator=(RPN& other);

        //check and set stacks
        void calculate();
};


#endif