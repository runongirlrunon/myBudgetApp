/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudget
 * main.cpp
 *************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "Budget.hpp"

using namespace std;

enum selection {
    exit_Program,
    show_Budget,
    make_Deposit,
    make_Withdrawal
};


// main function declarations
void endProgram();

int setSelection();
string setFileName();
void readFile(string);
void writeBudgetToFile(Budget&);

void showBudget(Budget&);
Budget loadBudget();
void storeBudget(Budget&);
void destroyBudget(Budget&);
// end function declarations


int main(int argc, const char * argv[]) {
    Budget currentBudget;
    int selection, acctID;
    double amount;
    
    // initializing sample Budget
    currentBudget.setBudgetTitle("MyBudget");
    currentBudget.addEnvelope(1, "Rent");
    currentBudget.addEnvelope(2, "Groceries");
    currentBudget.addAccount(123, "Checking", 10.00);
    currentBudget.addAccount(456, "Savings", 100.00);
    
    do {
        selection = setSelection();
        if (selection == exit_Program){
            break;
        }
        else if (selection == show_Budget) {
            showBudget(currentBudget);
        }
        else if (selection == make_Deposit){
            cout << endl << "Enter account ID: ";
            cin >> acctID;
            cin.ignore();
            cout << "Enter deposit amount: ";
            cin >> amount;
            cin.ignore();
            currentBudget.accountDeposit(acctID, amount);
            cout << endl;
        }
        else if (selection == make_Withdrawal){
            cout << endl << "Enter account ID: ";
            cin >> acctID;
            cin.ignore();
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            cin.ignore();
            currentBudget.accountWithdrawal(acctID, amount);
            cout << endl;
        }
        else {
            cout << "Input invalid. Try again." << endl;
        }
    }while (selection != exit_Program);
    
    endProgram();
    return 0;
} // end main

int setSelection(){
    int input = 0;
    cout << "SELECT AN OPTION:" << endl;
    cout << "1. Show budget" << endl;
    cout << "2. Make Deposit" << endl;
    cout << "3. Make Withdrawal" << endl;
    cout << "0. EXIT" << endl;
    cout << "Enter your selection: ";
    cin >> input;
    cin.ignore();
    return input;
} // end setSelection

void showBudget(Budget& budget){
    cout << "----- " << budget.getBudgetTitle() << " -----" << endl;
    cout << budget.getBudgetAcctCount() << " Accounts:" << endl;
    for (int loopCount = 0; loopCount < budget.getBudgetAcctCount(); loopCount++) {
        cout << budget.getAccount(loopCount).getAcctId() << ": ";
        cout << budget.getAccount(loopCount).getAcctTitle() << " - ";
        cout << budget.getAccount(loopCount).getAcctBalance() << endl;
    }
    cout << endl;
    cout << budget.getBudgetEnvCount() << " Envelopes:" << endl;
    for (int loopCount = 0; loopCount < budget.getBudgetEnvCount(); loopCount++) {
        cout << budget.getEnvelope(loopCount).getEnvId() << ": ";
        cout << budget.getEnvelope(loopCount).getEnvTitle() << endl;
    }
    cout << endl;
} // end showBudget

Budget loadBudget(){
    Budget newBudget;
    ifstream inStream;
    inStream.open("BUDGET");
    if(inStream.fail()){
        cout << "BUDGET file does not exist." << endl << endl;
    }
    
    else{
        inStream >> newBudget;
    }
    
    return newBudget;
} // end loadBudget

void storeBudget(Budget& budget){
    ofstream outStream;
    outStream.open("BUDGET", ios::app);
    outStream << budget;
} // end storeBudget

void endProgram(){
    cout << "Goodbye!" << endl;
} // end endProgram




















