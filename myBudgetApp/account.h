/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * account.h
 *************************************/

#ifndef account_h
#define account_h

#include <stdio.h>
#include <string>
#include "budget_item.h"

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

#endif /* account_h */