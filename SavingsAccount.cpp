/***********************************************************************
// OOP244 Workshop #7
//
// File:    SavingsAccount.cpp
// Version: 1.0
// Author:  Marquez DaSilva
//
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string>

#include "SavingsAccount.h"
#include "BankAccount.h"
#include "DepositUtility.h"

namespace seneca {

	SavingsAccount::SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate) : BankAccount(name, openDate, depInfo, balance)
	{
		m_interest = interest;
		m_interestDate = interestDate;

	}

	void SavingsAccount::writeInterest(std::ostream& out) const
	{
		out.setf(std::ios::fixed);
		out.precision(3);
		out << m_interest << "%";
	}

	void SavingsAccount::applyInterest(Date& dt)
	{

		std::cout.setf(std::ios::fixed);
		std::cout.precision(2);
		double bal = getBalance();
		double interest = bal* m_interest;

		std::cout << "   ";
		writeCurrency(std::cout, bal);
		std::cout << " + ";
		writeCurrency(std::cout, interest);
		std::cout << " (";
		writeInterest(std::cout);
		bal += interest;
		std::cout << ") = ";
		writeCurrency(std::cout, bal);
		std::cout << " | ";
		m_interestDate.write(std::cout);
		std::cout << " => ";
		m_interestDate = dt;
		m_interestDate.write(std::cout);
		setBalance(bal);
		std::cout << std::endl;

	}
	std::ostream& SavingsAccount::write(std::ostream& out) const
	{
		
		BankAccount::write(out);
		out << " | ";
		writeInterest(out);
		out << " | ";
		m_interestDate.write(out);

		return out;

	}

	std::istream& SavingsAccount::read(std::istream& in)
	{
		
		BankAccount::read(in);

		
		std::cout << "Interest Date ";
		m_interestDate.read(in);
		std::cout << "Interest Rate: ";
		in >> m_interest;

		return in;

	}

	std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct)
	{

		return acct.write(out);

	}

	std::istream& operator>>(std::istream& in, SavingsAccount& acct)
	{
		
		return acct.read(in);

	}

	

}



