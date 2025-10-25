/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange_Parser.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:18:09 by daeunki2          #+#    #+#             */
/*   Updated: 2025/10/24 23:41:17 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::parse_db(const std::string& filename, std::map<std::string, float>& container)
{
    std::ifstream db_file(filename);
    
    if (!db_file.is_open())
    {
        throw BitcoinExchange::Bitcoin_Error("Error: can't open database file.\n");
    }
    
    std::string line;
    
    std::getline(db_file, line);
	if (line != "date,exchange_rate")
		throw BitcoinExchange::Bitcoin_Error("Error: first line. should be [date,exchange_rate].\n");

    while (std::getline(db_file, line))
    {
        if (line.empty() || line[0] == '#')
            throw BitcoinExchange::Bitcoin_Error("Error: db does not allow empty line in middle.\n");
    }
}



