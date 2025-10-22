/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:00:17 by daeunki2          #+#    #+#             */
/*   Updated: 2025/10/22 15:41:08 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
: db_file(""), search_file("")
{

}

BitcoinExchange::BitcoinExchange(const std::string& dbFile, const std::string& searchFile)
: db_file(dbFile), search_file(searchFile)
{
    std::ifstream dbStream(db_file.c_str());
    if (!dbStream.is_open())
        throw Bitcoin_Error("Error: could not open database file.");
	dbStream.close();
    std::ifstream searchStream(search_file.c_str());
    if (!searchStream.is_open())
        throw Bitcoin_Error("Error: could not open input file.");
	searchStream.close();
	parse_db(db_file, db);
    parse_search(search_file, to_find);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
: db(src.db), to_find(src.to_find), db_file(src.db_file), search_file(src.search_file)
{

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
	{
		db = src.db;
		to_find = src.to_find;
		db_file = src.db_file;
		search_file = src.search_file;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}
BitcoinExchange::Bitcoin_Error::Bitcoin_Error(const std::string& message)
: std::runtime_error(message)
{
	
}