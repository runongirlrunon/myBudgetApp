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
#include "BudgetApplication.hpp"

using namespace std;

// This little function is just to be sure that everything exits
// and ends like it's supposed to. :)
void endProgram();

int main(int argc, const char * argv[]) {
    BudgetApplication *myBudgetApp = new BudgetApplication;
    
    while(myBudgetApp->is_running()){
        myBudgetApp->prompt_loop();
    }
        
    endProgram();
    return 0;
} // end main

void endProgram(){
    cout << "Goodbye!" << endl;
} // end endProgram



















