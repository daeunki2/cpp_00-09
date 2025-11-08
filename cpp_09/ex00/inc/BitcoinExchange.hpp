/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:59:57 by daeunki2          #+#    #+#             */
/*   Updated: 2025/11/08 14:36:10 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <stdexcept>
#include <fstream>
#include "Error.hpp"

enum type
{
	DATABASE,
	SEARCH,
};

class BitcoinExchange
{
	private:
	std::map<std::string, float> db;
	std::multimap<std::string, float> to_find;
	std::string db_file;
	std::string search_file;

	
	std::string& trim(std::string& str);
	bool is_good_date(const std::string& date);
	bool is_valid(const std::string& line, type type);
	bool is_good_value(const std::string& value);
	void check_all_error(const std::string& value);


	

	void parse_db(const std::string& filename, std::map<std::string, float>& container);

	public:
	BitcoinExchange();
	BitcoinExchange(const std::string& searchFile);
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange& operator=(const BitcoinExchange& src);
	~BitcoinExchange();

const std::map<std::string, float>& get_db_ref() const;



	void search_and_print(const std::string& filename);
};

#endif
