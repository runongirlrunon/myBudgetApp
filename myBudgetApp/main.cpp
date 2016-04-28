/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * main.cpp
 *************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "budget.hpp"
#include "budget_application.hpp"

int main()
{
    BudgetApplication app;
    
    while( app.is_running() ) {
        app.prompt_loop();
    }
}


















