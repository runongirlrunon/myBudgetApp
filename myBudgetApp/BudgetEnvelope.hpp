/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * BudgetEnvelope.hpp
 *************************************/

#ifndef BudgetEnvelope_hpp
#define BudgetEnvelope_hpp

#include <stdio.h>
#include "BudgetItem.hpp"

#endif /* BudgetEnvelope_hpp */

class BudgetEnvelope : public BudgetItem {
public:
    bool withdraw(double amount);
};