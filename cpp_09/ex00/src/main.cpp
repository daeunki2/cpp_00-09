/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:43:00 by daeunki2          #+#    #+#             */
/*   Updated: 2025/10/06 11:03:48 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"
#include <list>
#include <vector>

int main()
{
    
    
    std::cout << "================== [std::vector Test] ==================\n";
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    std::cout << "your vector = ";    
    std::copy(vec.begin(), 
              vec.end(), 
              std::ostream_iterator<int>(std::cout, " | "));
    std::cout << std::endl;
    std::cout << "Let's try to find if trere is 20 and 99" << std::endl;
    int val1 = 20;
    try
    {
        std::vector<int>::const_iterator it = easyfind(vec, val1);
        std::cout << "[SUCCESS] Value " << val1 << " found: " << *it << "\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "[FAILURE] " << e.what() << "\n";
    }
    int val2 = 99;
    try
    {
        easyfind(vec, val2);
        std::cout << "[ERROR] Should have failed but didn't.\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "[FAILURE] " << val2 << " search failed: " << e.what() << "\n";
    }
    
    std::cout << "\n==================== [std::list Test] ====================\n";

    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);
    std::cout << "your list = ";    
    std::copy(lst.begin(), 
              lst.end(), 
              std::ostream_iterator<int>(std::cout, " | "));
    std::cout << std::endl;
    std::cout << "Let's try to find if trere is 300 and 150" << std::endl;
    int val4 = 300;
    try
    {
        std::list<int>::const_iterator it = easyfind(lst, val4);
        std::cout << "[SUCCESS] Value " << val4 << " found: " << *it << "\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "[FAILURE] " << e.what() << "\n";
    }
    int val5 = 150;
    try
    {
        easyfind(lst, val5);
        std::cout << "[ERROR] Should have failed but didn't.\n";
    }
    catch (const std::exception& e)
    {
        // 예상대로 예외가 잡힘
        std::cout << "[FAILURE] " << val5 << " search failed: " << e.what() << "\n";
    }
    
    std::cout << "========================================================\n";

    return 0;
}