
#ifndef ERROR_HPP
#define ERROR_HPP

#include <stdexcept>
#include <string>
#include <iostream>
#include "Error.hpp"

#define RESET          "\x1B[0m"
#define RED            "\x1B[31m"
#define LIGHT_RED      "\x1B[91m"
#define YELLOW         "\x1B[33m"
#define CYAN           "\x1B[36m"
#define LIGHTMAGENTA   "\x1B[95m"

class PemergeMe_error : public std::runtime_error
{
public:
	enum ErrorType
	{
		DEFAULT,
		PARSE,
		LOGIC,
	};

private:
	ErrorType _type;

public:
	//Orthodox Canonical Form
	PemergeMe_error();														
	explicit PemergeMe_error(const std::string& msg, ErrorType type = DEFAULT);
	PemergeMe_error(const PemergeMe_error& other);
	PemergeMe_error& operator=(const PemergeMe_error& other);
	virtual ~PemergeMe_error() throw();

	void print() const;
	ErrorType getType() const;
};

#endif