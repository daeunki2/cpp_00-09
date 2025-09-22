/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:48:36 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/21 23:05:39 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include<iostream>

template <typename T>
class Array
{
	private:
	    T* data; //starting point
	    unsigned int size;

	public:
		Array();
    	Array(unsigned int n);
    	Array(const Array& other);
    	~Array();

	    // 연산자 오버로딩 (operator overloading)
	    Array& operator=(const Array& other);
	    T& operator[](unsigned int index);
	    const T& operator[](unsigned int index) const;

	    // 멤버 함수 (member functions)
	    unsigned int getSize() const;
};

#include "../src/Array.tpp" 

#endif