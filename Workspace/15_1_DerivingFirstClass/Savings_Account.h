#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

#include "Account.h"    // inherit from Account

class Savings_Account : public Account {
public:
    double int_rate;    // interest rate

    Savings_Account();              // constructor
    ~Savings_Account();             // destructor

    void deposit(double amount);    // override deposit
    void withdraw(double amount);   // override withdraw
};

#endif // _SAVINGS_ACCOUNT_H_
