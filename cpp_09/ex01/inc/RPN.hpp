/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:12:30 by daeunki2          #+#    #+#             */
/*   Updated: 2025/10/22 14:19:57 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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