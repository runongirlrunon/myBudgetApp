/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudget
 * Account.cpp
 *************************************/

#include "Account.hpp"

using namespace std;

/*************************************
 * constructors
 *************************************/

Account::Account(){
    id = 0;
    title = "No title";
    balance = 0.0;
}
Account::Account(int idValue, string titleValue, double balanceValue){
    id = idValue;
    title = titleValue;
    balance = balanceValue;
}

/*************************************
 * getters and setters
 *************************************/

int Account::getAcctId(){
    return id;
}
void Account::setAcctId(int idValue){
    id = idValue;
}
string Account::getAcctTitle(){
    return title;
}
void Account::setAcctTitle(string titleValue){
    title = titleValue;
}
double Account::getAcctBalance(){
    return balance;
}
void Account::setAcctBalance(double balanceValue){
    balance = balanceValue;
}

bool Account::withdraw(double amount){
    balance -= amount;
    if(balance < 0){
        return false;
    }
    return true;
}