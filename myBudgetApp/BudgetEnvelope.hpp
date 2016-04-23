//
//  BudgetEnvelope.hpp
//  myBudgetApp
//
//  Created by lindsey anne on 4/21/16.
//  Copyright © 2016 Lindsey Hogg. All rights reserved.
//

#ifndef BudgetEnvelope_hpp
#define BudgetEnvelope_hpp

#include <stdio.h>
#include "BudgetItem.hpp"

#endif /* BudgetEnvelope_hpp */

class BudgetEnvelope : public BudgetItem {
public:
    bool withdraw(double amount);
};