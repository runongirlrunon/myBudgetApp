/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * envelope_box.cpp
 *************************************/

#include "envelope_box.h"

using namespace std;

EnvelopeBox::EnvelopeBox(const EnvelopeLabel* newRoot){
    // no further constructor needed, dates get set in budget constructor
} // end constructor

void EnvelopeBox::setDates(int monthValue, int yearValue){
    month = monthValue;
    year = yearValue;
} // end setDates

void EnvelopeBox::deposit(int id, double amount){
    BudgetEnvelope searchKey = *new BudgetEnvelope(id, "searchKey");
    Node<BudgetEnvelope>* keyPtr = envelopes.find(searchKey);
    BudgetEnvelope myValue = keyPtr->value;
    myValue.deposit(amount);
} // end deposit

bool EnvelopeBox::withdraw(int id, double amount){
    BudgetEnvelope searchKey = *new BudgetEnvelope(id, "searchKey");
    Node<BudgetEnvelope>* keyPtr = envelopes.find(searchKey);
    BudgetEnvelope myValue = keyPtr->value;
    return myValue.withdraw(amount);
} // end withdraw