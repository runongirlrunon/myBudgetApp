/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * budget_application.cpp
 *************************************/

#include <iostream>
#include "budget_application.h"
#include "budget.h"
#include "menu.h"

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
    /* 
     commented out lines in this section would be used if we wanted
     to define the behavior for withdrawing/depositing money within
     the BudgetEnvelopes.
     */
    
    int acctID;
//    int typeOfTransaction;
    double amount;
    if (myMenu->last_selection() == exit_Program){
        return;
    }
    else if (myMenu->last_selection() == show_Budget) {
        myBudget->showBudget();
    }
    else if (myMenu->last_selection() == make_Deposit){
//        cout << endl << "Deposit to: " << endl << "  1. Account" << endl << "  2. Envelope" << endl;
//        cin >> typeOfTransaction;
        
//        if(typeOfTransaction == 1){
            cout << endl << "Enter account ID: ";
            cin >> acctID;
            cin.ignore();
            cout << "Enter deposit amount: ";
            cin >> amount;
            cin.ignore();
            myBudget->accountDeposit(acctID, amount);
            cout << endl;
//        }
//        else{
//            cout << endl << "Enter envelope ID: ";
//            cin >> acctID;
//            cin.ignore();
//            cout << "Enter deposit amount: ";
//            cin >> amount;
//            cin.ignore();
//            myBudget->envelopeDeposit(acctID, amount);
//            cout << endl;
//        }
    }
    else if (myMenu->last_selection() == make_Withdrawal){
//        if(typeOfTransaction == 1){
            cout << endl << "Enter account ID: ";
            cin >> acctID;
            cin.ignore();
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            cin.ignore();
            myBudget->accountWithdrawal(acctID, amount);
            cout << endl;
//        }
//        else{
//            cout << endl << "Enter envelope ID: ";
//            cin >> acctID;
//            cin.ignore();
//            cout << "Enter withdrawal amount: ";
//            cin >> amount;
//            cin.ignore();
//            myBudget->envelopeWithdrawal(acctID, amount);
//            cout << endl;
//        }
    }
    else {
        cout << "Input invalid. Try again." << endl;
    }
    cin.clear();
} // end process_menu_selection