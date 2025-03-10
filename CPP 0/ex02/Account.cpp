/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelacou <hdelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:12:38 by raveriss          #+#    #+#             */
/*   Updated: 2025/02/27 20:19:35 by hdelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;         // nombre total de comptes
int Account::_totalAmount = 0;        // somme totale des comptes
int Account::_totalNbDeposits = 0;    // nombre total de depots
int Account::_totalNbWithdrawals = 0; // nombre total de retraits

/*
	Initialise un compte avec un dépôt initial, met à jour les statistiques
	globales et affiche un message
*/
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}
/*
	.
		-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                               Destructeur                                 |
	'
		-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/

/*
	Met à jour les statistiques lorsqu'un compte est fermé et affiche un
	message.
*/
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	_nbAccounts--;
}
/*
	.
		-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   .
	|                      Méthodes Statiques d'Accès                           |
	'
		-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-',-'   '
*/

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}
/*
 *   Affiche les informations globales de tous les comptes.
 *   Inclut le nombre total de comptes, le montant total,
 *   le nombre total de dépôts et le nombre total de retraits.
 *   @return void
 */
void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

/**
 *   Affiche les informations du compte courant.
 *   @return void
 */
void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

/**
 *   Ajoute une somme d'argent au compte courant en prenant en compte
 *   les statistiques globales.
 *   @param  deposit  Somme à ajouter au solde du compte (en dollars).
 *   @return void
 */
void Account::makeDeposit(int deposit)
{
	_totalAmount += deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
		- deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

/**
 *   Retire une somme d'argent du compte courant en prenant en compte
 *   les statistiques globales.
 *   @param  withdrawal  Somme à retirer du solde du compte (en dollars).
 *   @return true si le retrait est possible, false sinon.
 */
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
}

int Account::checkAmount() const
{
	return (_amount);
}

void Account::_displayTimestamp()
{
	std::time_t time = std::time(0);
	std::tm now = *std::localtime(&time);
	std::cout << "[" << (now.tm_year
		+ 1900) << std::setfill('0') << std::setw(2) << now.tm_mon
		+ 1 << std::setw(2) << now.tm_mday << "_" << std::setw(2) << now.tm_hour << std::setw(2) << now.tm_min << std::setw(2) << now.tm_sec << "] ";
}
