//
//  BudgetEnvelope.cpp
//  myBudgetApp
//
//  Created by lindsey anne on 4/21/16.
//  Copyright © 2016 Lindsey Hogg. All rights reserved.
//

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