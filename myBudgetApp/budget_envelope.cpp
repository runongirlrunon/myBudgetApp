/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * budget_envelope.cpp
 *************************************/

#include <iostream>
#include <fstream>
#include "budget_envelope.h"

using namespace std;

/*************************************
 * constructors
 *************************************/

BudgetEnvelope::BudgetEnvelope(){
    id = 0;
    name = "";
    balance = 0;
}

BudgetEnvelope::BudgetEnvelope(int idValue, string nameValue){
    id = idValue;
    name = nameValue;
}

/*************************************
 * helper functions
 *************************************/

bool BudgetEnvelope::withdraw(double amount){
    if((balance -= amount) < 0){
        return false;
    }
    else{
        balance -= amount;
    }
    return true;
}

bool BudgetEnvelope::deposit(double amount){
    balance += amount;
    return true;
}

/*************************************
 * friendly overloaded operators
 *************************************/

bool operator==(const BudgetEnvelope& leftSide, const BudgetEnvelope& rightSide){
    return (leftSide.id == rightSide.id);
}

bool operator<(const BudgetEnvelope& leftSide, const BudgetEnvelope& rightSide) {
    return (leftSide.id < rightSide.id);
}

ostream& operator<<(ostream& outputStream, const BudgetEnvelope& envelope){
    outputStream << envelope.id << " " << envelope.name << endl;
    return outputStream;
}

ofstream& operator<<(ofstream& outFileStream, const BudgetEnvelope& envelope){
    outFileStream << envelope.id << " " << envelope.name << endl;
    return outFileStream;
}

ifstream& operator>>(ifstream& inFileStream, BudgetEnvelope& envelope){
    inFileStream >> envelope.id >> envelope.name;
    return inFileStream;
}
