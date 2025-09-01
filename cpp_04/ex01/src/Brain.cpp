/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:33:55 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/31 21:13:07 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain()
{
    set_idea("no_idea");
    std::cout << "new brain" << std::endl;
}

Brain::Brain(std::string idea)
{
    set_idea(idea);
    std::cout << "new brain with idea " << idea << std::endl;
}

// 복사 생성자
Brain::Brain(const Brain& src) 
{
    *this = src;
    std::cout << "new brain (copied)" << std::endl;
}

// 소멸자
Brain::~Brain()
{
    std::cout << "no more brain" << std::endl;
}

Brain& Brain::operator=(const Brain& src)
{
    if (this != &src) {
        for (int i = 0; i < 100; i++)
            this->idea[i] = src.idea[i];
    }
    std::cout << "Brain copy assignment operator" << std::endl;
    return *this;
}

void Brain::set_idea(std::string idea)
{
	for(int i = 0; i < 100; i++)
	{
		this->idea[i] = idea;
	}
}
std::string Brain::get_idea(int n)
{
	if (n >= 0 && n < 100)
        return this->idea[n];
    return "";
}