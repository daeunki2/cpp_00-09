/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:01:00 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/21 19:02:59 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime> //time()


int main()
{
    srand(time(NULL));

    std::cout << "----------------------Starting tests-------------------------" << std::endl;

    for (int i = 0; i < 10; ++i)
    {
        std::cout << "\n--- Test " << i + 1 << " ---" << std::endl;

        Base* randomObject = generate();
		
		std::cout << "generate A, B,C, and upcast to base " << std::endl;
        std::cout << "Identifying by pointer: ";
        identify(randomObject);

        std::cout << "Identifying by reference: ";
        identify(*randomObject);

        delete randomObject;
        randomObject = NULL;
    }

    std::cout << "\n-----------------------------------------------" << std::endl;
    std::cout << "All tests finished." << std::endl;

    return 0;
}