/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:00:22 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/21 18:58:23 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


/*
Base * generate(void);
무작위로 A, B, 또는 C를 인스턴스화하고, 그 인스턴스를 Base 포인터로 반환합니다. 무작위 선택 구현에는 원하는 것을 자유롭게 사용하세요.

void identify(Base* p);
p가 가리키는 객체의 실제 타입을 "A", "B", 또는 "C"로 출력합니다.

void identify(Base& p);
p가 참조하는 객체의 실제 타입을 "A", "B", 또는 "C"로 출력합니다. 이 함수 내에서는 포인터를 사용하는 것이 금지됩니다.
*/

Base* generate()
{
    int random_number = rand() % 3;

    if (random_number == 0)
	{
        return static_cast<Base*> (new A());//upcasting by programer
    }
	else if (random_number == 1)
	{
        return new B();//upcasting by compiler
    }
	else
	{
        return new C();
    }
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "I'm A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "I'm B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "I'm C" << std::endl;
	else
		std::cout << "I have a problem" << std::endl;
};


void identify(Base& p)
{
    try
    {
        A &temp = dynamic_cast<A&>(p);
		(void)temp;
        std::cout << "I am A" << std::endl;
        return ;
    }
    catch (const std::bad_cast& e){ }
    
    try
    {
        B &tmp = dynamic_cast<B&>(p);
		(void)tmp;
        std::cout << "I am B" << std::endl;
        return ;
    }
    catch (const std::bad_cast& e){ }

    try
    {
        C &temp = dynamic_cast<C&>(p);
		(void)temp;
        std::cout << "I am C" << std::endl;
        return ; 
    }
    catch (const std::bad_cast& e){ }

    std::cout << "I have a problem" << std::endl;
};
