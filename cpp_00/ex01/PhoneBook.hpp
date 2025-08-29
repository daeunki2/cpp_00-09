/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:14:49 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/29 22:36:39 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream> // cout, cin
#include <string> // string
#include <cctype> // isalpha
#include <cstdlib> 
#include <iomanip>
#include "Contact.hpp"

//class for a book
class PhoneBook
{
    private :
    Contact	Pages[8];
	int		Contact_Count;
	int		Oldest_Index;

	public :
	PhoneBook();

    void 		add();
	void 		search();
	void 		show_all_contacts() const;
	void		show_detail_page(int index);
};

std::string fit(const std::string &s);


#endif