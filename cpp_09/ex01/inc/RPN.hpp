/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:12:30 by daeunki2          #+#    #+#             */
/*   Updated: 2025/11/08 15:17:33 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_HPP
#define RPN_HPP

#include <string>    // string
#include <stack>     // stack
#include <stdexcept> // exception
#include <iostream>  // cin cout
#include <sstream>   // sstream
#include "Error.hpp" // RPN_error를 위해 필요하다고 가정

class RPN
{
    private:
        std::string input;
        std::stack<double> operand_stack;  // number
    
    public:
        // Orthodox Canonical Form
        RPN();
        RPN(std::string argv);
        ~RPN();
        RPN(const RPN& other);               // const 추가
        RPN& operator=(const RPN& other);    // const 추가

        void calculate();
};


#endif