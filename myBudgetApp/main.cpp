/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * main.cpp
 *************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "budget.h"
#include "budget_application.h"

int main()
{
    BudgetApplication app;
    
    while( app.is_running() ) {
        app.prompt_loop();
    }
}


















