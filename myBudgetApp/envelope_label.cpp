/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * envelope.cpp
 *************************************/

#include "envelope_label.h"

/*************************************
 * constructors
 *************************************/

EnvelopeLabel::EnvelopeLabel(){
    id = 0;
    title = "No title";
}
EnvelopeLabel::EnvelopeLabel(int idValue, string titleValue){
    id = idValue;
    title = titleValue;
}

/*************************************
 * getters and setters
 *************************************/

int EnvelopeLabel::getEnvId(){
    return id;
}
void EnvelopeLabel::setEnvId(int idValue){
    id = idValue;
}
string EnvelopeLabel::getEnvTitle(){
    return title;
}
void EnvelopeLabel::setEnvTitle(string titleValue){
    title = titleValue;
}
