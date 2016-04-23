/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * BudgetItem.hpp
 *************************************/

#ifndef BudgetItem_hpp
#define BudgetItem_hpp

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

#endif /* BudgetItem_hpp */
