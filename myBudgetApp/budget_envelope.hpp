/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * budget_envelope.hpp
 *************************************/

#ifndef budget_envelope_hpp
#define budget_envelope_hpp

#include <stdio.h>
#include "budget_item.hpp"

class BudgetEnvelope : public BudgetItem {
public:
    bool withdraw(double amount);
    
    // friendly overloaded operators
    friend bool operator<(const BudgetEnvelope& leftSide, const BudgetEnvelope& rightSide);
    friend bool operator==(const BudgetEnvelope& leftSide, const BudgetEnvelope& rightSide);
};

#endif /* budget_envelope_hpp */