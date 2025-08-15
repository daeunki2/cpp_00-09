/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:43:09 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/15 14:51:46 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
먼저, 클래스를 구현해야 합니다! 얼마나 창의적인가요!
클래스 이름은 ClapTrap이며, 다음과 같은 private 속성을 가집니다. 괄호 안의 값으로 초기화됩니다:

Name: 생성자에 전달되는 값
Hit points (10): ClapTrap의 체력
Energy points (10)
Attack damage (0)

*/

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream> // cout, cin
#include <cmath> //round

class ClapTrap
{
	private :
	std::string		name;
	unsigned int	HitPoint;
	unsigned int	EnergyPoint;
	unsigned int	AttackDamage;
	

	public :
	ClapTrap();
    ClapTrap(std::string input);
	ClapTrap(const ClapTrap& src);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif