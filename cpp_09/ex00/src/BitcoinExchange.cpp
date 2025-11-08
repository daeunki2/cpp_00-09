/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:00:17 by daeunki2          #+#    #+#             */
/*   Updated: 2025/11/08 14:54:05 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/******************************************************************************/
/*                        	Orthodox Canonical Form                           */
/******************************************************************************/

BitcoinExchange::BitcoinExchange()
:db_file("src/data.csv")
{
	parse_db(db_file, db);
}

BitcoinExchange::BitcoinExchange(const std::string& searchFile)
:db_file("src/data.csv"), search_file(searchFile)
{
	parse_db(db_file, db);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	db = src.db;
	db_file = src.db_file;
	to_find = src.to_find;
	search_file = src.search_file;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
	{
		db = src.db;
		db_file = src.db_file;
		to_find = src.to_find;
		search_file = src.search_file;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	
}


/******************************************************************************/
/*                            	Parsing helper                                */
/******************************************************************************/

std::string& BitcoinExchange::trim(std::string& str)
{
    const char *whitespace = " \t";
    
    size_t start = str.find_first_not_of(whitespace);
    if (start == std::string::npos)
    {
        str.clear();
        return str;
    }
    str.erase(0, start);

    size_t end = str.find_last_not_of(whitespace);
    if (end != std::string::npos)
    {
        str.erase(end + 1);
    }
    
    return str;
}

bool BitcoinExchange::is_valid(const std::string& line, type type)
{
    int count = 0;
    if (type == DATABASE)
    {
        for (size_t i = 0; i < line.size(); i++)
        {
            if (line[i] != '-' && line[i] != ',' && line[i] != '.' && !(line[i] >= '0' && line[i] <= '9'))
                return false;
            if (line[i] == ',')
                count++;
        }
        
        if (count == 1 || count == 2)
            return true;
        return false;
    }
    else if (type == SEARCH)
    {
        for (size_t i = 0; i < line.size(); i++)
        {
            if (line[i] != '-' && line[i] != '|' && line[i] != ' ' && line[i] != '.' && !(line[i] >= '0' && line[i] <= '9'))
                return false;
            if (line[i] == '|')
                count++;
        }
        if (count == 1 )
            return true;
        return false;
    }
    else
        return false;
}

bool BitcoinExchange::is_good_date(const std::string& date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
    
    for (int i = 0; i < 10; ++i) 
    {
        if (i == 4 || i == 7)
            continue;
        
        if (date[i] < '0' || date[i] > '9')
            return false;
    }

    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;
        
    if (day < 1 || day > 31)
        return false;
    return true;
}

bool BitcoinExchange::is_good_value(const std::string& value)
{
    if (value.empty()) return false;
    for (size_t i = 0; i < value.size(); i++)
    {
        if ((value[i] < '0' || value[i] > '9') && value[i] != '.')
            return false;
    }
    return true;
}

void BitcoinExchange::check_all_error(const std::string& value)
{
	int count = 0;
	size_t i;
	if (value.empty())
		throw ::Bitcoin_Error(std::string("value is empty "),  ::Bitcoin_Error::PARSE);
	for (i = 0; i < value.size(); i++)
    {
		if (i != 0 && (value[i] == '+' || value[i] == '-'))
			throw ::Bitcoin_Error(std::string("can not use + ot - in middle "),  ::Bitcoin_Error::PARSE);
        if ((value[i] < '0' || value[i] > '9') && value[i] != '.')
            throw ::Bitcoin_Error(std::string("not a positive number."),  ::Bitcoin_Error::PARSE);
		if (value[i] == '.')
			count++;
    }
	if (value[0] == '.' || value[i] == '.')
		throw ::Bitcoin_Error(std::string("number can not start or finish with . "),  ::Bitcoin_Error::PARSE);
	if (count != 1 && count != 0)
		throw ::Bitcoin_Error(std::string("only 1 . can be used "),  ::Bitcoin_Error::PARSE);
	
	float value_float = std::strtof(value.c_str(), NULL);
	if (value_float >= 1000)
		throw ::Bitcoin_Error(std::string("too large a number. "),  ::Bitcoin_Error::PARSE);
	if (value_float < 0)
		throw ::Bitcoin_Error(std::string("not a positive number."),  ::Bitcoin_Error::PARSE);
		
}
/******************************************************************************/
/*                            	      Parsing                                 */
/******************************************************************************/

const std::map<std::string, float>& BitcoinExchange::get_db_ref() const
{
    return db;
}

void BitcoinExchange::parse_db(const std::string& filename, std::map<std::string, float>& container)
{
    std::ifstream input(filename.c_str());
    if (!input.is_open())
        throw ::Bitcoin_Error(std::string("Cannot open file: ") + filename, ::Bitcoin_Error::FILE);

    std::string from_file;
    if (!getline(input, from_file))
        throw ::Bitcoin_Error(std::string("Cannot read file: ") + filename, ::Bitcoin_Error::FILE);

    if (from_file != "date,exchange_rate")
        throw ::Bitcoin_Error(std::string("First line error: ") + filename, ::Bitcoin_Error::PARSE);

    std::string line;
    while (getline(input, line))
    {
        if (!is_valid(line, DATABASE))
            throw ::Bitcoin_Error(std::string("Data line should only have digits, '-' and ',' in file: ") + filename, ::Bitcoin_Error::PARSE);

        std::stringstream ss(line);
        std::string date, value;

        getline(ss, date, ',');
        if (!is_good_date(date))
            throw ::Bitcoin_Error(std::string("Invalid date format in file: ") + filename, ::Bitcoin_Error::PARSE);

        getline(ss, value, ',');
        if (!is_good_value(value))
            throw ::Bitcoin_Error(std::string("Invalid value format in file: ") + filename, ::Bitcoin_Error::PARSE);

        float value_float = std::strtof(value.c_str(), NULL);
        container[date] = value_float;
    }
}

void BitcoinExchange::search_and_print(const std::string& filename)
{
    std::ifstream input(filename.c_str());

    if (!input.is_open())
        throw ::Bitcoin_Error(std::string("could not open file: ") + filename, ::Bitcoin_Error::FILE);

    std::string from_file;
    if (!getline(input, from_file))
        throw ::Bitcoin_Error(std::string("Cannot read file: ") + filename, ::Bitcoin_Error::FILE);

    if (trim(from_file) != "date | value") 
        throw ::Bitcoin_Error(std::string("First line error: ") + filename, ::Bitcoin_Error::PARSE);
        
    std::string line;
    while (getline(input, line))
    {
        if (!is_valid(line, SEARCH))
        {
            std::cerr << RED << "Error bad input => " << line << RESET << std::endl;
            continue;
        }

        std::stringstream ss(line);
        std::string date, value;

        getline(ss, date, '|');
        getline(ss, value, '|');

        trim(date);
        trim(value);
        
        try
        {
            if (date.empty() || !is_good_date(date))
                throw ::Bitcoin_Error("Invalid date format", ::Bitcoin_Error::PARSE);
            
            if (value.empty())
                throw ::Bitcoin_Error("value is empty", ::Bitcoin_Error::PARSE);
            check_all_error(value); 

            float value_float = std::strtof(value.c_str(), NULL);
            if (value_float == 0.0 && value.c_str() != std::string("0"))
            	throw ::Bitcoin_Error("not a positive number.", ::Bitcoin_Error::PARSE);


            std::map<std::string, float>::iterator it = db.lower_bound(date);

            
            if (it == db.end())
            {
                if (db.empty())
                    throw ::Bitcoin_Error("Database is empty.", ::Bitcoin_Error::DATE);
                it = --db.end();
            }
            else if (it->first != date)
            {
                if (it == db.begin())
                {
                    throw ::Bitcoin_Error("Date is before the earliest record in DB: " + date, ::Bitcoin_Error::DATE);
                }
                --it;
            }
            
            float result = value_float * it->second;
            std::cout << date << " => " << value_float << " = " << result << std::endl;
        }
        catch (const ::Bitcoin_Error& e)
        {
            if (e.getType() == ::Bitcoin_Error::PARSE)
            {
                std::cerr << RED << "Error : " << e.what() << RESET << std::endl;
            }
            else if (e.getType() == ::Bitcoin_Error::VALUE)
            {
                std::cerr << YELLOW << "Error : " << e.what() << RESET << std::endl;
            }
            else if (e.getType() == ::Bitcoin_Error::DATE)
            {
                e.print();
            }
            else
            {
                std::cerr << RED << "Error " << e.what() << RESET << std::endl;
            }
        }
    }
}