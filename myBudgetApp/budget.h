/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * budget.h
 *************************************/

#ifndef budget_h
#define budget_h

#include <stdio.h>
#include <string>
#include "budget_item.h"
#include "account.h"
#include "envelope_label.h"
#include "envelope_box.h"

using namespace std;

class Budget{
private:
    string title;
    int envelope_count;
    EnvelopeLabel *envelopeLabels = new EnvelopeLabel[0];
    int account_count;
    Account *accounts = new Account[0];
    
    int currentMonth, currentYear;
    EnvelopeBox *currentEnvBox = new EnvelopeBox(envelopeLabels);
    
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
    int getBudgetAcctCount();
    
    // helper functions
    void addEnvelope(int idValue, string titleValue);
    void addAccount(int idValue, string titleValue, double balanceValue);
    EnvelopeLabel getEnvelope(int position);
    Account getAccount(int position);
    void showBudget();
    void accountDeposit(int id, double amount);
    void accountWithdrawal(int id, double amount);
    void envelopeDeposit(int id, double amount);
    void envelopeWithdrawal(int id, double amount);
    
    // friendly overloaded operators
    friend ostream& operator<<(ostream& outputStream, const Budget& thisBudget);
    friend ofstream& operator<<(ofstream& outputFileStream, const Budget& thisBudget);
    friend ifstream& operator>>(ifstream& inputFileStream, Budget& thisBudget);
};

#endif /* budget_h */
