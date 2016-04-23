/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * Account.hpp
 *************************************/

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>
#include <string>
#include "BudgetItem.hpp"

using namespace std;

class Account : public BudgetItem {  
public:
    // constructors
    Account();
    Account(int idValue, string titleValue, double balanceValue);
    
    // getters and setters
    int getAcctId();
    void setAcctId(int idValue);
    string getAcctTitle();
    void setAcctTitle(string titleValue);
    double getAcctBalance();
    void setAcctBalance(double balanceValue);
    bool withdraw(double amount);
};

#endif /* Account_hpp */