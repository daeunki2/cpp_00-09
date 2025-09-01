/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 00:40:25 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/01 00:42:19 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

// 기본 생성자 - 타입 "cure" 설정
Cure::Cure() : AMateria("ice")
{
	
}

// 소멸자
Cure::~Cure()
{
	
}

// 복사 생성자
Cure::Cure(const Cure &src) : AMateria(src)
{
	
}

// 대입 연산자
Cure &Cure::operator=(const Cure &src)
{
    if (this != &src)
        _type = src.getType(); // 부모 AMateria의 _type 복사
    return *this;
}

// clone() - 새로운 Cure 객체 생성
AMateria* Cure::clone() const
{
    return new Cure(*this);
}

// use() - 마법 사용 출력
void Cure::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}