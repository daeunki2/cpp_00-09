/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:13:38 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/24 04:04:19 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string search_replace(const std::string& original,  const std::string& to_search, const std::string& to_replace)
{
    if (to_search.empty()) 
        return original;

    std::string result;
    size_t pos = 0;
    size_t found;
    
    while ((found = original.find(to_search, pos)) != std::string::npos)
    {
        result.append(original, pos, found - pos);
        result.append(to_replace);
        pos = found + to_search.length();
    }
    result.append(original, pos, std::string::npos);

    return result;
}


int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::string filename = av[1];
        std::string s1 = av[2];
        std::string s2 = av[3];

        
		if (s1.empty())
        {
            std::cerr << "Error: String to find must not be empty." << std::endl;
            return 1;
        }

		std::ifstream inputFile;
		inputFile.open(av[1]);
		if (!inputFile.is_open())
        {
            std::cerr << "Error: Cannot open file " << filename << std::endl;
            return 1;
        }
        
        std::ofstream outputFile;
		outputFile.open((filename + ".replace").c_str());
        if (!outputFile.is_open())
        {
            std::cerr << "Error: Cannot create output file " << filename + ".replace" << std::endl;
            return 1;
        }

        std::string line;
        while (std::getline(inputFile, line))
        {
            outputFile << search_replace(line, s1, s2) <<"\n";
        }

        inputFile.close();
        outputFile.close();

        std::cout << "File created: " << filename + ".replace" << std::endl;
    }
    else
    {
        std::cout << "Usage: ./program filename string1 string2" << std::endl;
        return 1;
    }

    return 0;
}

//valgrind --leak-check=full --track-fds=yes