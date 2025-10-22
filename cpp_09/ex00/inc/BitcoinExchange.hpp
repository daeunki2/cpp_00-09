/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:59:57 by daeunki2          #+#    #+#             */
/*   Updated: 2025/10/22 15:39:12 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <fstream>

class BitcoinExchange
{
	private:
	std::map<std::string, float> db;
	std::multimap<std::string, float> to_find;
	std::string db_file;
	std::string search_file;

	void parse_db(const std::string& filename, std::map<std::string, float>& container);
	void parse_search(const std::string& filename, std::multimap<std::string, float>& container);


	public:
	BitcoinExchange();
	BitcoinExchange(const std::string& dbFile, const std::string& searchFile);
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange& operator=(const BitcoinExchange& src);
	~BitcoinExchange();

	void search_and_print() const;

	class Bitcoin_Error : public std::runtime_error
	{
		public:
		explicit Bitcoin_Error(const std::string& message);
	};
};

#endif
