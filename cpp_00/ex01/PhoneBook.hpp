/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:14:49 by daeunki2          #+#    #+#             */
/*   Updated: 2025/07/12 00:18:49 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream> // cout, cin
#include <string> // string
#include <cctype> // isalpha


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

	bool	set_first_name(const std::string &str);
	bool	set_last_name(const std::string &str);
	bool	set_nick_name(const std::string &str);
	bool	set_phone_number(const std::string &str);
	bool	set_darkest_secret(const std::string &str);
	
	std::string get_first_name() const { return first_name; }
    std::string get_last_name() const { return last_name; }
    std::string get_nick_name() const { return nick_name; }
    std::string get_phone_number() const { return phone_number; }
    std::string get_darkest_secret() const { return darkest_secret; }
	
	void write_page();
	void print_contact(int index) const
	{
		std::string index_str = coupcoup(std::to_string(index));
		if (index == 0)
		{
			std::cout << "______________________________________________" << std::endl;	
    		std::cout << "|Index     |First Name|Last Name |Nick Name |" << std::endl;
    		std::cout << "______________________________________________" << std::endl;	
		}
		std::cout << "|" << index_str << "|";
		std::cout << first_name << "|";
		std::cout << last_name << "|";
		std::cout << nick_name << "|"<<std::endl;;
		std::cout << "______________________________________________" << std::endl;	
	}
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

    void add_1_page();
	void print_contact_at(int index);

};

#endif