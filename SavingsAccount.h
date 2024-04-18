
/***********************************************************************
// OOP244 Workshop #7:
//
// File:    SavingsAccount.h
// Version: 1.0
// Author:  Marquez DaSilva
//
***********************************************************************/
#ifndef SENECA_SAVINGS_ACCOUNT_H
#define SENECA_SAVINGS_ACCOUNT_H

#include <iostream>
#include "DepositUtility.h"
#include "BankAccount.h"


namespace seneca {
	class SavingsAccount : public BankAccount {
	private: 

		double m_interest;
		Date m_interestDate;
		void writeInterest(std::ostream& out) const;

	public: 

		SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate);
		void applyInterest(Date& dt);
		std::ostream& write(std::ostream& out) const override;
		std::istream& read(std::istream& in) override;

	};

	std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct);
	std::istream& operator>>(std::istream& in, SavingsAccount& acct);
}

#endif