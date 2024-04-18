/***********************************************************************
// OOP244 Workshop #7
//
// File:    BankAccount.cpp
// Version: 1.0
// Author:  Marquez DaSilva
//
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string>

#include "BankAccount.h"
namespace seneca {

	BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance) 
	{
		
		strcpy(m_name, name);
		m_openDate = openDate;
		m_depInfo = depInfo;
		m_balance = balance;

	};

	double BankAccount::getBalance() const 
	{

		return m_balance;

	}

	void BankAccount::setBalance(double balance)
	{

		m_balance = balance;

	 }

	void BankAccount::writeCurrency(std::ostream& out, double amount) const 
	{

		out.setf(std::ios::fixed);
		out.precision(2);
		out << "$" << amount;
		out.unsetf(std::ios::fixed);
		out.precision(6);

	}

	std::ostream& BankAccount::write(std::ostream& out) const
	{

		out << ">> " << m_name << " | ";
		writeCurrency(out, m_balance);
		out << " | "; 
		m_openDate.write(out);
		out << " | ";
		m_depInfo.write(out);
		return	out;

	}

	std::istream& BankAccount::read(std::istream& in)
	{

		std::cout << "Name: ";
		if (in.peek() == '\n')
		{
			in.get();
		}
		in.getline(m_name, 50);

;		std::cout << "Opening Balance: ";
		in >> m_balance;

		std::cout << "Date Opened ";

		m_openDate.read(in);

		m_depInfo.read(in);

		return in;
	}


	std::ostream& operator<<(std::ostream& out, const BankAccount& acct)
	{

		return acct.write(out);
		
	}

	std::istream& operator>>(std::istream& in, BankAccount& acct)
	{

		return acct.read(in);

	}

}