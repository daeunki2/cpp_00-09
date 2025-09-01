/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:24:46 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/01 00:59:05 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    const Animal* meta = new Animal();
    std::cout << "------------- 🐾 Create Animal class meta 🐾 -----------------" << std::endl;

    const Animal* D = new Dog();
    std::cout << "------------- 🐾 Create Create Animal class D 🐾 -----------------" << std::endl;

    const Animal* C = new Cat();

    std::cout << "------------- 🐾 Create Create Animal class C 🐾 -----------------" << std::endl;
    
    std::cout << "------------- 🐱🐶 Polymorphism 🐱🐶 -----------------" << std::endl;
    std::cout << "Animal pointer D points to type: " << D->getType() << std::endl;
    std::cout << "Animal pointer C points to type: " << C->getType() << std::endl;

    std::cout << "Animal pointer D makes sound: ";
    D->makeSound();  // Dog sound

    std::cout << "Animal pointer C makes sound: ";
    C->makeSound();  // Cat sound

    std::cout << "Animal pointer meta makes sound: ";
    meta->makeSound();  // Animal sound

    std::cout << "\n=== ⚠️ If there is no virtual function ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
    std::cout << "WrongCat makes sound: ";
    wrongCat->makeSound();  // WrongAnimal 소리
    std::cout << "WrongMeta makes sound: ";
    wrongMeta->makeSound(); // WrongAnimal 소리

    std::cout << "\n⚠️ Since makeSound is not virtual, child class function is ignored!" << std::endl;

    std::cout << "\n------------- 🗑️ Destroy Objects 🗑️ -----------------" << std::endl;
    delete meta;
    delete D;
    delete C;
    delete wrongMeta;
    delete wrongCat;

    std::cout << "All objects cleaned up! ✅" << std::endl;

    return 0;
}

