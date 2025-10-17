#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>

class Account {
public:
    double balance;                 // public for now 
    std::string name;

    Account();                      // constructor
    ~Account();                     // destructor

    void deposit(double amount);    // deposit method
    void withdraw(double amount);   // withdraw method
};

#endif // _ACCOUNT_H_
