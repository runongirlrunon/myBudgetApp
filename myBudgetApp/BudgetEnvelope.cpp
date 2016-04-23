/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * BudgetEnvelope.cpp
 *************************************/

#include "BudgetEnvelope.hpp"

bool BudgetEnvelope::withdraw(double amount){
    if((balance -= amount) < 0){
        return false;
    }
    else{
        balance -= amount;
    }
    return true;
}