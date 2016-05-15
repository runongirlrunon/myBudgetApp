/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * envelope.h
 *************************************/

#ifndef envelope_label_h
#define envelope_label_h

#include <stdio.h>
#include <string>

using namespace std;

class EnvelopeLabel {
private:
    int id;
    string title;
    
public:
    // constructors
    EnvelopeLabel();
    EnvelopeLabel(int idValue, string titleValue);
    
    // getters and setters
    int getEnvId();
    void setEnvId(int idValue);
    string getEnvTitle();
    void setEnvTitle(string titleValue);
};

#endif /* envelope_label_h */
