/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:01:12 by daeunki2          #+#    #+#             */
/*   Updated: 2025/11/12 16:29:05 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Error.hpp"
#include <iostream>
#include <ctime>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe [numbers...]" << std::endl;
        return 1;
    }

    PmergeMe sorter;

    try
    {
        sorter.parseInput(argc, argv);
        sorter.sortAndDisplay();
    }
    catch (const PemergeMe_error &e)
    {
        e.print();
        return 1;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}


// #include "PmergeMe.hpp"
// #include "Error.hpp"

// int main(int argc, char **argv)
// {
//     if (argc < 2)
//     {
//         std::cerr << "Usage: ./PmergeMe [numbers...]" << std::endl;
//         return 1;
//     }

//     PmergeMe sorter;

//     try
//     {
//         sorter.parseInput(argc, argv);
//         sorter.sortAndDisplay();
//     }
//     catch (const PemergeMe_error::PemergeMe_error &e)
//     {
//         std::cerr << "Error: " << e.what() << std::endl;
//         return 1;
//     }
//     catch (const std::exception &e) // 일반 예외
//     {
//         std::cerr << "Unexpected error: " << e.what() << std::endl;
//         return 1;
//     }

//     return 0;
// }
