/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:51:27 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/11 00:02:04 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int 	Account::_totalNbDeposits = 0;
int 	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	this->_nbDeposits =0;
	this->_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"amount:" << this->checkAmount() << ";" <<
	"created" <<
	std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"amount:" << this->checkAmount() << ";" <<
	"closed" <<
	std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"p_amount:" << this->checkAmount() << ";" <<
	"deposit:" << deposit << ";";
	
	this-> _amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	
	std::cout <<
	"amount:" << this->checkAmount() << ";" <<
	"nb_deposits:" << this->_nbDeposits <<
	std::endl;
}

int		Account::checkAmount( void ) const
{
	return(this->_amount);
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"p_amount:" << this->checkAmount() << ";" <<
	"withdrawal:";
	if (this->_amount < withdrawal)
	{
		std::cout <<
		"refused" << std::endl;
		return (false);
	}
	else
	{
		this-> _amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout <<
		withdrawal << ";"
		"amount:" << this->checkAmount() << ";" <<
		"nb_withdrawals:" << this->_nbDeposits <<
		std::endl;
		return (true);
	}
}


void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"amount:" << this->checkAmount() << ";" <<
	"deposits:" << this->_nbDeposits << ";" <<
	"withdrawals:" << this->_nbWithdrawals <<
	std::endl;
}

int		Account::getNbAccounts( void )
{
	return(_nbAccounts);
}

int		Account::getTotalAmount( void )
{
	return(_totalAmount);
}
int		Account::getNbDeposits( void )
{
	return(_totalNbDeposits);
}
int		Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout <<
	"accounts:" << getNbAccounts( ) << ";" <<
	"total:" << getTotalAmount( ) << ";" <<
	"deposits:" << getNbDeposits( ) << ";" <<
	"withdrawals:" << getNbWithdrawals( ) << 
	std::endl;
}
void	Account::_displayTimestamp( void )
{
	std::cout << "[19920104_091532] ";
	// time_t now = std::time(NULL);
	// struct tm timenow = *std::localtime(&now);

	// std::cout << "[" << timenow.tm_year + 1900 <<
	// std::setfill('0') << std::setw(2) << timenow.tm_mon + 1 <<
	// std::setfill('0') << std::setw(2) << timenow.tm_mday << "_" <<
	// std::setfill('0') << std::setw(2) << timenow.tm_hour <<
	// std::setfill('0') << std::setw(2) << timenow.tm_min <<
	// std::setfill('0') << std::setw(2) << timenow.tm_sec <<
	// "] ";
}