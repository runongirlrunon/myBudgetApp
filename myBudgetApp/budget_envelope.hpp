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
};

#endif /* budget_envelope_hpp */