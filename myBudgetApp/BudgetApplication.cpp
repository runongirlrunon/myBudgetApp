/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * BudgetApplication.cpp
 *************************************/

#include <iostream>
#include "BudgetApplication.hpp"
#include "Budget.hpp"
#include "Menu.hpp"

using namespace std;

/*************************************
 * constructor/destructor
 *************************************/

BudgetApplication::BudgetApplication(){
    // no constructor code needed
} // end constructor

BudgetApplication::~BudgetApplication(){
    delete myBudget;
    delete myMenu;
} // end destructor

/*************************************
 * helper functions
 *************************************/

bool BudgetApplication::is_running(){
    if(myMenu->last_selection() != 0){
        return true;
    }
    return false;
} // end is_running

void BudgetApplication::prompt_loop(){
    myMenu->show_menu();
    myMenu->prompt_for_selection();
    process_menu_selection();
} // end prompt_loop

void BudgetApplication::process_menu_selection(){
    if (myMenu->last_selection() == exit_Program){
        return;
    }
    else if (myMenu->last_selection() == show_Budget) {
        myBudget->showBudget();
    }
    else if (myMenu->last_selection() == make_Deposit){
        int acctID;
        double amount;
        
        cout << endl << "Enter account ID: ";
        cin >> acctID;
        cin.ignore();
        cout << "Enter deposit amount: ";
        cin >> amount;
        cin.ignore();
        myBudget->accountDeposit(acctID, amount);
        cout << endl;
    }
    else if (myMenu->last_selection() == make_Withdrawal){
        int acctID;
        double amount;
        
        cout << endl << "Enter account ID: ";
        cin >> acctID;
        cin.ignore();
        cout << "Enter withdrawal amount: ";
        cin >> amount;
        cin.ignore();
        myBudget->accountWithdrawal(acctID, amount);
        cout << endl;
    }
    else {
        cout << "Input invalid. Try again." << endl;
    }
    
} // end process_menu_selection