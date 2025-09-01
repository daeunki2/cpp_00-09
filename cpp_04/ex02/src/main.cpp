/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:24:46 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/31 23:01:50 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include "AAnimal.hpp"


int main()
{
    Dog d;
    Cat c;

    std::cout << d.getType() << " says: ";
    d.makeSound();

    std::cout << c.getType() << " says: ";
    c.makeSound();

    // AAnimal a; // ❌ 컴파일 에러: 추상 클래스는 인스턴스화 불가
}
