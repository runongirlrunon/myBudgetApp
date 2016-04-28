/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * budget_envelope.cpp
 *************************************/

#include "budget_envelope.hpp"

bool BudgetEnvelope::withdraw(double amount){
    if((balance -= amount) < 0){
        return false;
    }
    else{
        balance -= amount;
    }
    return true;
}