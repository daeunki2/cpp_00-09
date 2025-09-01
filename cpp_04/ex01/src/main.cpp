/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:24:46 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/31 21:37:32 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int N = 4; // 테스트용 배열 크기 (2마리 강아지, 2마리 고양이)

    Animal* animals[N];

    // 절반은 Dog, 절반은 Cat 생성
    for (int i = 0; i < N; i++) {
        if (i < N / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- 테스트: 소리 내기 ---" << std::endl;
    for (int i = 0; i < N; i++)
    {
        animals[i]->makeSound();
    }

    std::cout << "\n--- 테스트: 깊은 복사 ---" << std::endl;
    Dog* originalDog = dynamic_cast<Dog*>(animals[0]);
    if (originalDog)
    {
        originalDog->setIdea("I want to play!");
        originalDog->showIdea(0);

        Dog copiedDog = *originalDog;
        copiedDog.showIdea(0);

        originalDog->setIdea("I am hungry!");
        std::cout << "\nAfter changing original:" << std::endl;
        std::cout << "original Dog's idea = ";
        originalDog->showIdea(0);
        std::cout << "copied Dog's idea = ";
        copiedDog.showIdea(0);
    }

    std::cout << "\n--- 배열 cleanup ---" << std::endl;
    for (int i = 0; i < N; i++)
        delete animals[i]; 

    return 0;
}
