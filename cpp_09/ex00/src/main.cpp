/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:00:25 by daeunki2          #+#    #+#             */
/*   Updated: 2025/11/08 14:36:00 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "BitcoinExchange.hpp"
#include "Error.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input.txt>" << std::endl;
        return 1;
    }

    std::string input_file = argv[1];

    try
    {
        BitcoinExchange btc(input_file);
        btc.search_and_print(input_file);
    }
    catch (const Bitcoin_Error& e)
    {
        std::cerr << "\x1B[91mException: " << e.what() << "\x1B[0m" << std::endl;
        return 1;
    }

    return 0;
}





// void BitcoinExchange::parse_input(const std::string& filename)
// {
//     std::ifstream input(filename.c_str());
//     if (!input.is_open())
//         throw ::Bitcoin_Error(std::string("Cannot open file: ") + filename, ::Bitcoin_Error::FILE);

//     std::string from_file;
//     if (!getline(input, from_file))
//         throw ::Bitcoin_Error(std::string("Cannot read file: ") + filename, ::Bitcoin_Error::FILE);

//     if (from_file != "date | value")
//         throw ::Bitcoin_Error(std::string("First line error: ") + filename, ::Bitcoin_Error::PARSE);

//     std::string line;
//     while (getline(input, line))
//     {
//         std::stringstream ss(line);
//         std::string date, value;

//         getline(ss, date, '|');
//         getline(ss, value, '|');

//         try
//         {
//             if (!is_valid(line, SEARCH))
//                 throw ::Bitcoin_Error("Data line should only have digits, '|' and '.'", ::Bitcoin_Error::PARSE);

//             if (!is_good_date(date))
//                 throw ::Bitcoin_Error("Invalid date format", ::Bitcoin_Error::PARSE);

//             check_all_error(value); // 숫자 체크 + 범위 체크

//             float value_float = std::strtof(value.c_str(), NULL);
//             to_find.insert(std::make_pair(date, value_float)); // 정상 데이터만 삽입
//         }
//         catch (const ::Bitcoin_Error& e)
//         {
//             // 컬러 출력
//             std::cerr << "\x1B[91m" << "Error in line: " << line << " -> " << e.what() << "\x1B[0m" << std::endl;
//             continue; // 한 줄 오류 발생해도 다음 줄 처리
//         }
//     }
// }
