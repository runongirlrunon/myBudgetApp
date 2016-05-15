/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * envelope_box.h
 *************************************/

#ifndef envelope_box_h
#define envelope_box_h

#include <stdio.h>
#include "budget_envelope.h"
#include "envelope_label.h"
#include "tree.h"

using namespace std;

class EnvelopeBox {
private:
    int month;
    int year;
    Tree<BudgetEnvelope> envelopes;
    
public:
    // constructor
    EnvelopeBox(const EnvelopeLabel*);
    void setDates(int monthValue, int yearValue);
    void deposit(int id, double amount);
    bool withdraw(int id, double amount);
};

#endif /* envelope_box_h */
