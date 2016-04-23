//
//  BudgetApplication.hpp
//  myBudgetApp
//
//  Created by lindsey anne on 4/21/16.
//  Copyright © 2016 Lindsey Hogg. All rights reserved.
//

#ifndef BudgetApplication_hpp
#define BudgetApplication_hpp

#include <stdio.h>
#include "Budget.hpp"
#include "Menu.hpp"

using namespace std;

enum selection {
    exit_Program,
    show_Budget,
    make_Deposit,
    make_Withdrawal
};

#endif /* BudgetApplication_hpp */

class BudgetApplication {
private:
    Budget *myBudget = new Budget;
    Menu *myMenu = new Menu;
    
    // private helper functions
    void process_menu_selection();
    
public:
    // constructor/destructor
    BudgetApplication();
    ~BudgetApplication();
    
    // public helper functions
    bool is_running();
    void prompt_loop();
};