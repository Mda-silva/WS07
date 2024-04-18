/***********************************************************************
// OOP244 Workshop #7:
//
// File:    BankAccount.h
// Version: 1.0
// Author:  Marquez DaSilva
//
***********************************************************************/
#ifndef SENECA_BANK_ACCOUNT_H
#define SENECA_BANK_ACCOUNT_H

#include <iostream> 
#include <cstring>
#include "DepositUtility.h"

const unsigned int NAME_LEN = 50;

namespace seneca {

	class BankAccount {
	private:

		char m_name[NAME_LEN + 1];
		Date m_openDate;
		DepositInfo m_depInfo;
		double m_balance;

	protected:

		double getBalance() const;
		void setBalance(double balance);
		void writeCurrency(std::ostream& out, double amount) const;

	public:

		BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);
		virtual std::ostream& write(std::ostream& out) const;
		virtual std::istream& read(std::istream& in);
		virtual ~BankAccount() {};

	};

	std::ostream& operator<<(std::ostream& out, const BankAccount& acct);
	std::istream& operator>>(std::istream& in, BankAccount& acct);

}

#endif