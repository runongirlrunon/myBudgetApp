/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudget
 * Budget.cpp
 *************************************/

#include <iostream>
#include <fstream>
#include "Budget.hpp"

using namespace std;

/*************************************
 * constructor/destructor
 *************************************/

Budget::Budget(){
    title = "default title";
    envelope_count = 0;
    account_count = 0;
} // end constructor

Budget::~Budget(){
    envelope_count = 0;
    account_count = 0;
    delete [] envelopes;
    delete [] accounts;
} // end destructor

/*************************************
 * getters and setters
 *************************************/

string Budget::getBudgetTitle(){
    return title;
}
void Budget::setBudgetTitle(string titleValue){
    title = titleValue;
}
int Budget::getBudgetEnvCount(){
    return envelope_count;
}
void Budget::setBudgetEnvCount(int envCountValue){
    envelope_count = envCountValue;
}
int Budget::getBudgetAcctCount(){
    return account_count;
}
void Budget::setBudgetAcctCount(int acctCountValue){
    account_count = acctCountValue;
}

/*************************************
 * helper functions
 *************************************/

void Budget::addEnvelope(int idValue, string titleValue){
    Envelope *envelopesTemp = new Envelope[envelope_count+1];
    // copy the old array first, if it exists
    if (envelope_count > 0) {
        for (int loopCount = 0; loopCount < envelope_count; loopCount++) {
            (envelopesTemp + loopCount)->setEnvId((envelopes + loopCount)->getEnvId());
            (envelopesTemp + loopCount)->setEnvTitle((envelopes + loopCount)->getEnvTitle());
        }
    }
    // then add the new value
    (envelopesTemp + envelope_count)->setEnvId(idValue);
    (envelopesTemp + envelope_count)->setEnvTitle(titleValue);
    envelopes = envelopesTemp;
    envelope_count++;
} // end addEnvelope

void Budget::addAccount(int idValue, string titleValue, double balanceValue){
    Account *accountsTemp = new Account[account_count+1];
    // copy the old array first, if it exists
    if (account_count > 0) {
        for (int loopCount = 0; loopCount < account_count; loopCount++) {
            (accountsTemp + loopCount)->setAcctId((accounts + loopCount)->getAcctId());
            (accountsTemp + loopCount)->setAcctTitle((accounts + loopCount)->getAcctTitle());
            (accountsTemp + loopCount)->setAcctBalance((accounts + loopCount)->getAcctBalance());
        }
    }
    // then add the new value
    (accountsTemp + account_count)->setAcctId(idValue);
    (accountsTemp + account_count)->setAcctTitle(titleValue);
    (accountsTemp + account_count)->setAcctBalance(balanceValue);
    accounts = accountsTemp;
    account_count++;
} // end addAccount

Envelope Budget::getEnvelope(int position){
    return envelopes[position];
} // end getEnvelope

Account Budget::getAccount(int position){
    return accounts[position];
} // end getAccount

void Budget::accountDeposit(int id, double amount){
    for (int i = 0; i < account_count; i++) {
        if(accounts[i].getAcctId() == id){
            accounts[i].setAcctBalance(accounts[i].getAcctBalance() + amount);
            return;
        }
    }
} // end accountDeposit

void Budget::accountWithdrawal(int id, double amount){
    for (int i = 0; i < account_count; i++) {
        if(accounts[i].getAcctId() == id){
            accounts[i].withdraw(amount);
            return;
        }
    }
} // end accountWithdrawal

/*************************************
  * friendly overloaded operators
 *************************************/

ostream& operator<<(ostream& outputStream, const Budget& budget){
    outputStream << budget.title << endl;
    outputStream << budget.envelope_count << endl;
    for (int loopcount = 0; loopcount < budget.envelope_count; loopcount++) {
        outputStream << budget.envelopes[loopcount].getEnvId() << " ";
        outputStream << budget.envelopes[loopcount].getEnvTitle() << endl;
    }
    outputStream << budget.account_count << endl;
    for (int loopcount = 0; loopcount < budget.account_count; loopcount++) {
        outputStream << budget.accounts[loopcount].getAcctId() << " ";
        outputStream << budget.accounts[loopcount].getAcctTitle() << endl;
    }
    return outputStream;
} // end ostream<< overload

ofstream& operator<<(ofstream& outFileStream, const Budget& budget){
    outFileStream << budget.title << endl;
    outFileStream << budget.envelope_count << endl;
    for (int loopcount = 0; loopcount < budget.envelope_count; loopcount++) {
        outFileStream << budget.envelopes[loopcount].getEnvId() << " ";
        outFileStream << budget.envelopes[loopcount].getEnvTitle() << endl;
    }
    outFileStream << budget.account_count << endl;
    for (int loopcount = 0; loopcount < budget.account_count; loopcount++) {
        outFileStream << budget.accounts[loopcount].getAcctId() << " ";
        outFileStream << budget.accounts[loopcount].getAcctTitle() << endl;
    }
    
    return outFileStream;
} // end ofstream<< overload

ifstream& operator>>(ifstream& inFileStream, Budget& budget){
    string nextWord;
    int idValue;
    string titleValue;
    double balanceValue;
    
    while (!inFileStream.eof()) {
        // get title
        inFileStream >> nextWord;
        budget.title = nextWord;
        
        // get envelope_count
        inFileStream >> nextWord;
        budget.envelope_count = stoi(nextWord);
        
        // add all envelopes
        for (int loopCount = 0; loopCount < budget.envelope_count; loopCount++) {
            inFileStream >> idValue;
            inFileStream >> titleValue;
            budget.addEnvelope(idValue, titleValue);
        }
        
        // get account_count
        inFileStream >> nextWord;
        budget.account_count =stoi(nextWord);
        
        // add all accounts
        for (int loopCount = 0; loopCount < budget.account_count; loopCount++) {
            inFileStream >> idValue;
            inFileStream >> titleValue;
            inFileStream >> balanceValue;
            budget.addAccount(idValue, titleValue, balanceValue);
        }
    }
    
    return inFileStream;
} // end ifstream>> overload











