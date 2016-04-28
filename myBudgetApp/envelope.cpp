/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * envelope.cpp
 *************************************/

#include "envelope.hpp"

/*************************************
 * constructors
 *************************************/

Envelope::Envelope(){
    id = 0;
    title = "No title";
}
Envelope::Envelope(int idValue, string titleValue){
    id = idValue;
    title = titleValue;
}

/*************************************
 * getters and setters
 *************************************/

int Envelope::getEnvId(){
    return id;
}
void Envelope::setEnvId(int idValue){
    id = idValue;
}
string Envelope::getEnvTitle(){
    return title;
}
void Envelope::setEnvTitle(string titleValue){
    title = titleValue;
}
