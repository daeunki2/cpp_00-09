/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:56:01 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/19 19:25:08 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream> // cout, cin
#include <string> // string
#include <cctype> // isalpha
#include <cstdlib> 
#include <iomanip>

enum Status {
    F_NAME = 0,
    L_NAME = 1,
    N_NAME = 2,
    P_NUM = 3,
    D_SECREAT = 4,
	FIELD_COUNT,
};

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
	~Contact();
	//setter
	void		set_first_name(const std::string& user_input);
	void		set_last_name(const std::string& user_input);
	void		set_nick_name(const std::string& user_input);
	void		set_phone_number(const std::string& user_input);
	void		set_darkest_secret(const std::string& user_input);
	//getter
	std::string	get_first_name() const;
	std::string	get_last_name() const;
	std::string	get_nick_name() const;
	std::string	get_phone_number() const;
	std::string	get_darkest_secret() const;
	//add
	bool set_contacts(const std::string &user_input, Status flag);
	void add_page();
};

std::string safe_str(const std::string &input);
std::string safe_number(const std::string &input);
bool is_number_string(const std::string &str);
bool is_alpha_string(const std::string &str);
std::string no_space(const std::string& str);


#endif