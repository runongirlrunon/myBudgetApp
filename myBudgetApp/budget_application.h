/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * budget_application.h
 *************************************/

#ifndef budget_application_h
#define budget_application_h

#include <stdio.h>
#include "Budget.h"
#include "Menu.h"

using namespace std;

enum selection {
    exit_Program,
    show_Budget,
    make_Deposit,
    make_Withdrawal
};

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


#endif /* budget_application_h */