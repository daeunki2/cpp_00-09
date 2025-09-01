/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:47:29 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/31 23:00:18 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

/*
동물 객체를 만드는 것은 결국 의미가 없습니다.
사실, 그들은 아무 소리도 내지 않습니다!
실수를 피하기 위해, 기본 Animal 클래스는 인스턴스화할 수 없도록 해야 합니다.
아무도 이 클래스를 인스턴스화할 수 없도록 수정하세요.
나머지 모든 것은 이전과 같이 작동해야 합니다.
원한다면 클래스 이름에 A 접두사를 붙여 Animal을 업데이트할 수 있습니다.
*/

#include <iostream>

class AAnimal
{
protected:
    std::string type;

    AAnimal();
    AAnimal(const std::string &input);
    AAnimal(const AAnimal &src);
    AAnimal& operator=(const AAnimal &src);
    virtual ~AAnimal();

public:
    virtual void makeSound() const = 0; // 순수 가상 함수
    std::string getType() const;
};

#endif