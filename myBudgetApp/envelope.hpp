/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * envelope.hpp
 *************************************/

#ifndef envelope_hpp
#define envelope_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Envelope {
private:
    int id;
    string title;
    
public:
    // constructors
    Envelope();
    Envelope(int idValue, string titleValue);
    
    // getters and setters
    int getEnvId();
    void setEnvId(int idValue);
    string getEnvTitle();
    void setEnvTitle(string titleValue);
};

#endif /* envelope_hpp */
