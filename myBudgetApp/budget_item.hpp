/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * budget_item.hpp
 *************************************/

#ifndef budget_item_hpp
#define budget_item_hpp

#include <stdio.h>
#include <string>

using namespace std;

class BudgetItem {
protected:
    int id;
    string title;
    double balance;
    
public:
    virtual bool withdraw(double amount) = 0;
};

#endif /* budget_item_hpp */
