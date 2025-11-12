/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:01:19 by daeunki2          #+#    #+#             */
/*   Updated: 2025/11/12 16:34:58 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <ctime>
#include <climits>
#include <algorithm>
#include <sstream>

#include "Error.hpp"


#define THRESHOLD 10
#define RESET2       "\033[0m"
#define BOLD_RED    "\033[1;31m"
#define BOLD_GREEN  "\033[1;32m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_BLUE   "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN   "\033[1;36m"
#define BOLD_WHITE  "\033[1;37m"

class PmergeMe
{
private:
	std::vector<int>	_vec;
	std::list<int>		_list;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &rhs);
	~PmergeMe();

	void printColored(const std::string &text, const std::string &colorCode);
	bool parseInput(int argc, char **argv);
	void sortAndDisplay();

private:
	void fordJohnsonSort(std::vector<int> &v);
	void fordJohnsonSort(std::list<int> &l);

	void Insert_sort(std::vector<int> &v);
	void Insert_sort(std::list<int> &l);
};

#endif
