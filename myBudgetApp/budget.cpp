/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * budget.cpp
 *************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include "budget.h"

using namespace std;

/*************************************
 * constructor/destructor
 *************************************/

Budget::Budget(){
    title = "";
    envelope_count = 0;
    account_count = 0;
    // initializing sample Budget
    ifstream inStream;
    inStream.open("budget");
    if(inStream.fail()){
        cout << "BUDGET file does not exist." << endl << endl;
    }
    
    else{
        inStream >> *this;
    }
    inStream.close();
    currentEnvBox->setDates(currentMonth, currentYear);
    
} // end constructor

Budget::~Budget(){
    ofstream outStream;
    outStream.open("budget");
    outStream << *this;
    outStream.close();
    
    envelope_count = 0;
    account_count = 0;
    delete [] envelopeLabels;
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

int Budget::getBudgetAcctCount(){
    return account_count;
}

void Budget::setMonth(int month){
    currentMonth = month;
}

void Budget::setYear(int year){
    currentYear = year;
}

/*************************************
 * helper functions
 *************************************/

void Budget::addEnvelope(int idValue, string titleValue){
    EnvelopeLabel *envelopesTemp = new EnvelopeLabel[envelope_count+1];
    // copy the old array first, if it exists
    if (envelope_count > 0) {
        for (int loopCount = 0; loopCount < envelope_count; loopCount++) {
            (envelopesTemp + loopCount)->setEnvId((envelopeLabels + loopCount)->getEnvId());
            (envelopesTemp + loopCount)->setEnvTitle((envelopeLabels + loopCount)->getEnvTitle());
        }
    }
    // then add the new value
    (envelopesTemp + envelope_count)->setEnvId(idValue);
    (envelopesTemp + envelope_count)->setEnvTitle(titleValue);
    envelopeLabels = envelopesTemp;
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

EnvelopeLabel Budget::getEnvelope(int position){
    return envelopeLabels[position];
} // end getEnvelope

Account Budget::getAccount(int position){
    return accounts[position];
} // end getAccount

void Budget::showBudget(){
    cout << "----- " << this->getBudgetTitle() << " -----" << endl;
    cout << this->getBudgetAcctCount() << " Accounts:" << endl;
    for (int loopCount = 0; loopCount < this->getBudgetAcctCount(); loopCount++) {
        cout << this->getAccount(loopCount).getAcctId() << ": ";
        cout << this->getAccount(loopCount).getAcctTitle() << " - ";
        cout << this->getAccount(loopCount).getAcctBalance() << endl;
    }
    cout << endl;
    cout << this->getBudgetEnvCount() << " Envelopes:" << endl;
    for (int loopCount = 0; loopCount < this->getBudgetEnvCount(); loopCount++) {
        cout << this->getEnvelope(loopCount).getEnvId() << ": ";
        cout << this->getEnvelope(loopCount).getEnvTitle() << endl;
    }
    cout << endl;
} // end showBudget

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

void Budget::envelopeDeposit(int id, double amount){
    currentEnvBox->deposit(id, amount);
} // end envelopeDeposit

void Budget::envelopeWithdrawal(int id, double amount){
    currentEnvBox->withdraw(id, amount);
} // end envelopeWithdrawal

/*************************************
 * friendly overloaded operators
 *************************************/

ostream& operator<<(ostream& outputStream, const Budget& budget){
    outputStream << budget.title << endl;
    outputStream << budget.envelope_count << endl;
    for (int loopcount = 0; loopcount < budget.envelope_count; loopcount++) {
        outputStream << budget.envelopeLabels[loopcount].getEnvId() << " ";
        outputStream << budget.envelopeLabels[loopcount].getEnvTitle() << endl;
    }
    outputStream << budget.account_count << endl;
    for (int loopcount = 0; loopcount < budget.account_count; loopcount++) {
        outputStream << budget.accounts[loopcount].getAcctId() << " ";
        outputStream << budget.accounts[loopcount].getAcctTitle() << " ";
        outputStream << budget.accounts[loopcount].getAcctBalance() << endl;
    }
    outputStream << budget.currentMonth << " " << budget.currentYear << endl;
    return outputStream;
} // end ostream<< overload

ofstream& operator<<(ofstream& outFileStream, const Budget& budget){
    outFileStream << budget.title << endl;
    outFileStream << budget.envelope_count << endl;
    for (int loopcount = 0; loopcount < budget.envelope_count; loopcount++) {
        outFileStream << budget.envelopeLabels[loopcount].getEnvId() << " ";
        outFileStream << budget.envelopeLabels[loopcount].getEnvTitle() << endl;
    }
    outFileStream << budget.account_count << endl;
    for (int loopcount = 0; loopcount < budget.account_count; loopcount++) {
        outFileStream << budget.accounts[loopcount].getAcctId() << " ";
        outFileStream << budget.accounts[loopcount].getAcctTitle() << " ";
        outFileStream << budget.accounts[loopcount].getAcctBalance() << endl;
    }
    outFileStream << budget.currentMonth << " " << budget.currentYear << endl;
    
    return outFileStream;
} // end ofstream<< overload

ifstream& operator>>(ifstream& inFileStream, Budget& budget){
    string nextWord;
    int idValue;
    string titleValue;
    double balanceValue;
    
    // get title
    inFileStream >> nextWord;
    budget.setBudgetTitle(nextWord);
    
    // get envelope_count
    inFileStream >> nextWord;
    int envCount = stoi(nextWord);
    
    // add all envelopes
    for (int loopCount = 0; loopCount < envCount; loopCount++) {
        inFileStream >> idValue;
        inFileStream >> titleValue;
        budget.addEnvelope(idValue, titleValue);
    }
    
    // get account_count
    inFileStream >> nextWord;
    int acctCount = stoi(nextWord);
    
    
    // add all accounts
    for (int loopCount = 0; loopCount < acctCount; loopCount++) {
        inFileStream >> idValue;
        inFileStream >> titleValue;
        inFileStream >> balanceValue;
        budget.addAccount(idValue, titleValue, balanceValue);
    }
    
    // get file dates
    inFileStream >> nextWord;
    budget.setMonth(stoi(nextWord));
    inFileStream >> nextWord;
    budget.setYear(stoi(nextWord));
    
    return inFileStream;
} // end ifstream>> overload











