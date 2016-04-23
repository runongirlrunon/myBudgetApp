/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * BudgetApplication.hpp
 *************************************/

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


#endif /* BudgetApplication_hpp */