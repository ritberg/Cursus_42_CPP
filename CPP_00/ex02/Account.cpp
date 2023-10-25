/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:23:22 by mmakarov          #+#    #+#             */
/*   Updated: 2023/10/22 18:23:24 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Account.hpp"

/* 
    Initialization of member variables from Account class 

    "This" (I didn't use it) is normally used to disambiguate between
    class member variables and local variables with the same name,
    and to access class members within the scope of a class member function
*/
int	Account::_nbAccounts = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalAmount = 0;

/* Constructor */
Account::Account(int initial_deposit)
{
    _accountIndex = 0;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _amount = initial_deposit;
    _accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" <<_amount
			<< ";created" << std::endl;
	return;
}

/* Destructor */
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
			<< ";closed" << std::endl;
	return;
}

int	Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

/*
    now = time(NULL) returns the current time

    The localtime function takes a time_t variable
    (in this case, now) and converts it to a pointer to
    a tm structure containing various time components
    such as year, month, day, hour, minute, and second

    [%Y%m%d_%H%M%S]: This is a format string that specifies
    how the time should be displayed.
    %Y represents the year
    %m represents the month
    %d represents the day
    %H represents the hour
    %M represents the minute
    %S represents the second.
    The square brackets are included as part of the format string
*/
void	Account::_displayTimestamp(void)
{
    time_t	now;

	now = time(NULL);
	std::cout << std::put_time(localtime(&now), "[%Y%m%d_%H%M%S] ");
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
	std::cout << "index:"<< _accountIndex << ";amount:" <<_amount
			<< ";deposits:" << _nbDeposits << ";withdrawals:"
            << _nbWithdrawals << std::endl;
	return;
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
			<< ";deposits:" << getNbDeposits() << ";withdrawals:"
            << getNbWithdrawals() << std::endl;
	return;
}

/*
    Change logs, for ex: P_amount=42, deposit=5,amount=47, number of deposits=1
    Total amount and total number of deposits also increase
*/
void	Account::makeDeposit(int deposit)
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
        << ";deposit:" << deposit << ";amount:" << _amount + deposit
		<< ";nb_deposits:" << ++_nbDeposits << std::endl;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

/*
    Change logs, for ex: p_amount=819, withdrawal=34,amount=785, number of withdrawals=1
    Total amount decreases and total number of withdrawals increas

    If amount - withdrawal is less than 0, the withdrawal is refused
    Ex: amount=47, withdrawal=321, so it will be refused
    (cf. w[] = { 321, 34, 657, 4, 76, 275, 657, 7654 } in tests.cpp)
*/
bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    if (_amount - withdrawal > 0)
    {
        std::cout << ";withdrawal:" << withdrawal
            << ";amount:" << _amount - withdrawal
            << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        return (true);
    }
    else
    {
        std::cout << ";withdrawal:" << "refused" << std::endl;
        return (false);
    }
}
