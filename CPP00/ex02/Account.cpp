#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	_nbAccounts++;
	_totalAmount += initial_deposit;
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account( void )
{
	_amount = 0;
	_accountIndex = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
}

Account::~Account()
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << " closed" << std::endl;
}

int		Account::checkAmount( void ) const
{
	return _amount;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (_amount > withdrawal)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:" << withdrawal << 
";amount:" << _amount << ";nb_withdrawals:1" << std::endl;

		return true;
	}
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
	return false;
}

void	Account::makeDeposit( int deposit )
{
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" <<  deposit <<\
";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}


int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}
	

void	Account::_displayTimestamp( void )
{
	std::time_t now_time = std::time(0);  
    std::tm* now_tm = std::localtime(&now_time);  

    std::cout << "[" << (1900 + now_tm->tm_year) << std::setw(2) << std::setfill('0') << (now_tm->tm_mon + 1) \
<< std::setw(2) << std::setfill('0') << now_tm->tm_mday << "_" \
<< std::setw(2) << std::setfill('0') << now_tm->tm_hour << std::setw(2) << std::setfill('0') << now_tm->tm_min \
<< std::setw(2) << std::setfill('0') << now_tm->tm_sec << "] ";

}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";amount:" << _totalAmount << ";deposits:" <<  _totalNbDeposits <<\
";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const
{

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";total:" << _amount << ";deposits:" <<  _nbDeposits <<\
";withdrawals:" << _nbWithdrawals << std::endl;

}

