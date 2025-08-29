/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:24:46 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 15:24:18 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
    const Animal* meta = new Animal();
    const Animal* D = new Dog();
    const Animal* C = new Cat();
	std::cout << "------------- create-----------------" <<std::endl;


	std::cout << "\n\n\n\n"<<std::endl;
	std::cout << "------------- Polymorphism-----------------" <<std::endl;
    std::cout << "Animal claa D's type = " << D->getType() << " " << std::endl;
    std::cout << "Animal claa C's type = "<< C->getType() << " " << std::endl;
    std::cout << "Animal claa D's sound = " ;
	D->makeSound();
	std::cout << "Animal claa C's sound = " ;
    C->makeSound(); // dog sound
	std::cout << "Animal claa meta's sound = " ;
    meta->makeSound(); // animal sound


	std::cout << "\n\n\n\n"<<std::endl;
	std::cout << "----------- NO_Polymorphism-------------" <<std::endl;


	// const WrongAnimal *meta = new WrongCat();
	
	
	std::cout << "\n\n\n\n"<<std::endl;
	std::cout << "-------------distroiy-----------------" <<std::endl;
    delete meta;
    delete D;
    delete C;

    return 0;
}

//최상위 소멸자를 가상으로 하면 알아서 잘 다 지워짐