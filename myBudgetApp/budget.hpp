/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * budget.hpp
 *************************************/

#ifndef budget_hpp
#define budget_hpp

#include <stdio.h>
#include <string>
#include "budget_item.hpp"
#include "envelope.hpp"
#include "account.hpp"

using namespace std;

class Budget{
private:
    string title;
    int envelope_count;
    Envelope *envelopes = new Envelope[0];
    int account_count;
    Account *accounts = new Account[0];
    
    int currentMonth, currentYear;
    
    void setMonth(int month);
    void setYear(int year);
    
public:
    // constructor/destructor
    Budget();
    ~Budget();
    
    // getters and setters
    string getBudgetTitle();
    void setBudgetTitle(string titleValue);
    int getBudgetEnvCount();
//    void setBudgetEnvCount(int envCountValue);
    int getBudgetAcctCount();
//    void setBudgetAcctCount(int acctCountValue);
    
    // helper functions
    void addEnvelope(int idValue, string titleValue);
    void addAccount(int idValue, string titleValue, double balanceValue);
    Envelope getEnvelope(int position);
    Account getAccount(int position);
    void showBudget();
    void accountDeposit(int id, double amount);
    void accountWithdrawal(int id, double amount);
    
    // friendly overloaded operators
    friend ostream& operator<<(ostream& outputStream, const Budget& thisBudget);
    friend ofstream& operator<<(ofstream& outputFileStream, const Budget& thisBudget);
    friend ifstream& operator>>(ifstream& inputFileStream, Budget& thisBudget);
};

#endif /* budget_hpp */
