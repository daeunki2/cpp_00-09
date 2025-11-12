/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:02:02 by daeunki2          #+#    #+#             */
/*   Updated: 2025/11/12 16:50:44 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/******************************************************************************/
/*                        	Orthodox Canonical Form                           */
/******************************************************************************/

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &other) 
{
    *this = other; 
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) 
{
	if (this != &rhs)
	{
		this->_vec = rhs._vec;
		this->_list = rhs._list;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{

}

/******************************************************************************/
/*                        	         Init                                     */
/******************************************************************************/

bool PmergeMe::parseInput(int argc, char **argv)
{
	for(int i = 1; i < argc; i++)
	{
		std::string tmp = argv[i];
		for(size_t k = 0; k < tmp.length(); k++)
		
		if(isdigit(tmp[k]) == false)
			throw ::PemergeMe_error("[" + tmp + "] is not a positive integer", ::PemergeMe_error::PARSE);
		long value = atol(argv[i]);
		if (value < 0 || value > INT_MAX)
		{
			throw ::PemergeMe_error("[" + tmp + "] is out of range", ::PemergeMe_error::PARSE);
		}
		_vec.push_back(static_cast<int>(value));
		_list.push_back(static_cast<int>(value));
	}
	return true;
}


/******************************************************************************/
/*                        	         Helper                                   */
/******************************************************************************/

void PmergeMe::Insert_sort(std::vector<int> &v)
{
    int size = v.size();
    int outer, inner, key;

    for (outer = 1; outer < size; outer++)
    {
        key = v[outer];        // 현재 삽입할 값
        inner = outer;

        while (inner > 0 && v[inner - 1] > key)
        {
            v[inner] = v[inner - 1];  // 한 칸 뒤로 이동
            inner--;
        }
        v[inner] = key;  // key 삽입
    }
}

void PmergeMe::Insert_sort(std::list<int> &l)
{
    if (l.size() <= 1) return;

    std::list<int>::iterator it = l.begin();
    ++it;

    for (; it != l.end(); ++it)
    {
        int key = *it;
        std::list<int>::iterator j = it;
        --j;

        while (true)
        {
            if (*j <= key || j == l.begin()) break;
            std::list<int>::iterator next = j;
            ++next;
            *next = *j;
            if (j == l.begin()) { j = l.begin(); break; }
            --j;
        }
        std::list<int>::iterator insert_pos = j;
        if (*insert_pos > key) ++insert_pos;
        *insert_pos = key;
    }
}


/******************************************************************************/
/*                        	        Sorting                                   */
/******************************************************************************/

void PmergeMe::fordJohnsonSort(std::vector<int> &v)
{
    int size = v.size();
    if (size <= THRESHOLD)
    {
        Insert_sort(v);
        return;
    }

    // 배열 반으로 나누기
    int mid = size / 2;
    std::vector<int> left(v.begin(), v.begin() + mid);
    std::vector<int> right(v.begin() + mid, v.end());

    // 재귀 호출
    fordJohnsonSort(left);
    fordJohnsonSort(right);

    // 병합
    std::vector<int> merged;
    int i = 0, j = 0;
    while (i < (int)left.size() && j < (int)right.size())
    {
        if (left[i] <= right[j])
            merged.push_back(left[i++]);
        else
            merged.push_back(right[j++]);
    }
    while (i < (int)left.size()) merged.push_back(left[i++]);
    while (j < (int)right.size()) merged.push_back(right[j++]);

    // 원본 벡터에 복사
    v = merged;
}

void PmergeMe::fordJohnsonSort(std::list<int> &l)
{
    if (l.size() <= THRESHOLD)
    {
        Insert_sort(l); 
        return;
    }

    std::list<int>::iterator mid_it = l.begin();
    int mid = l.size() / 2;
    for (int i = 0; i < mid; ++i) ++mid_it;

    std::list<int> left(l.begin(), mid_it);
    std::list<int> right(mid_it, l.end());

    fordJohnsonSort(left);
    fordJohnsonSort(right);

    // 병합
    std::list<int> merged;
    std::list<int>::iterator it_left = left.begin();
    std::list<int>::iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end())
    {
        if (*it_left <= *it_right)
        {
            merged.push_back(*it_left);
            ++it_left;
        }
        else
        {
            merged.push_back(*it_right);
            ++it_right;
        }
    }
    while (it_left != left.end())
    {
        merged.push_back(*it_left);
        ++it_left;
    }
    while (it_right != right.end())
    {
        merged.push_back(*it_right);
        ++it_right;
    }

    l = merged; // 원본 리스트에 복사
}


/******************************************************************************/
/*                        	        Printer                                   */
/******************************************************************************/

void PmergeMe::printColored(const std::string &text, const std::string &colorCode)
{
    std::cout << colorCode << text << RESET2;
}

void PmergeMe::sortAndDisplay()
{
	printColored("---------------------------------------------------\n", BOLD_WHITE);
	printColored("Before sort: ", BOLD_GREEN);
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	clock_t start = clock();
	fordJohnsonSort(_vec);
	clock_t end = clock();
	double vecTime = double(end - start) / CLOCKS_PER_SEC * 1000.0;

	start = clock();
	fordJohnsonSort(_list);
	end = clock();
	double listTime = double(end - start) / CLOCKS_PER_SEC * 1000.0;

	printColored("After sort: ", BOLD_GREEN);
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
std::stringstream ss;
ss << vecTime;
printColored("---------------------------------------------------\n", BOLD_WHITE);
printColored("Time with vector: ", BOLD_MAGENTA);
printColored( ss.str() + " ms\n", BOLD_MAGENTA);

ss.str(""); ss.clear();
ss << listTime;
printColored("Time with list: ", BOLD_CYAN);
printColored(ss.str() + " ms\n", BOLD_CYAN);
}