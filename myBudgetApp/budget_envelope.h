/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * budget_envelope.h
 *************************************/

#ifndef budget_envelope_h
#define budget_envelope_h

#include <stdio.h>
#include "budget_item.h"
#include "envelope_label.h"

using namespace std;

class BudgetEnvelope : public BudgetItem {
private:
    int id;
    string name;
public:
    // constructors
    BudgetEnvelope();
    BudgetEnvelope(int idValue, string nameValue);
    
    // helper functions
    bool withdraw(double amount);
    bool deposit(double amount);
    
    // friendly overloaded operators
    friend bool operator==(const BudgetEnvelope& leftSide, const BudgetEnvelope& rightSide);
    friend bool operator<(const BudgetEnvelope& leftSide, const BudgetEnvelope& rightSide);
    
    friend ostream& operator<<(ostream&, const BudgetEnvelope&);
    friend ofstream& operator<<(ofstream&, const BudgetEnvelope&);
    friend ifstream& operator>>(ifstream&, BudgetEnvelope&);
};

#endif /* budget_envelope_h */