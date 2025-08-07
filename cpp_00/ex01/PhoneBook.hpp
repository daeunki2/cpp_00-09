/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:14:49 by daeunki2          #+#    #+#             */
/*   Updated: 2025/07/15 14:00:03 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream> // cout, cin
#include <string> // string
#include <cctype> // isalpha


enum Status {
    F_NAME = 0,
    L_NAME = 1,
    N_NAME = 2,
    P_NUM = 3,
    D_SECREAT = 4,
	FIELD_COUNT,
};

/// the functions for checking the users input and triming the inputs
std::string safe_str(const std::string &input);
std::string safe_number(const std::string &input);
std::string coupcoup(const std::string &input);
std::string trim(const std::string& str);
bool is_alpha_string(const std::string &str);
bool is_number_string(const std::string &str);

/// class for a page. 
class Contact
{
    private :
    std::string		first_name;
    std::string		last_name;
    std::string		nick_name;
    std::string		phone_number;
    std::string		darkest_secret;

    public :
	Contact();

	bool set_contacts(const std::string &user_input, Status flag);
	void write_page();
	void print_a_detail_page();
	void print_one_line(int index) const;
};

//class for a book
class PhoneBook
{
    private :
    Contact	Pages[8];
	int		Contact_Count;
	int		Oldest_Index;
	
	public : 
	PhoneBook();

    void add();
	void search();
	void show_all_contacts();
};

#endif