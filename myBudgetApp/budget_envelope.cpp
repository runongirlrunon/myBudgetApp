/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * budget_envelope.cpp
 *************************************/

#include "budget_envelope.hpp"

/*************************************
 * helper functions
 *************************************/

bool BudgetEnvelope::withdraw(double amount){
    if((balance -= amount) < 0){
        return false;
    }
    else{
        balance -= amount;
    }
    return true;
}

/*************************************
 * friendly overloaded operators
 *************************************/

bool operator<(const BudgetEnvelope& leftSide, const BudgetEnvelope& rightSide) {
    return (leftSide.id < rightSide.id);
}

bool operator==(const BudgetEnvelope& leftSide, const BudgetEnvelope& rightSide){
    return (leftSide.id == rightSide.id);
}