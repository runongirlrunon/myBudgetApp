/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * menu.h
 *************************************/

#ifndef menu_h
#define menu_h

#include <stdio.h>

using namespace std;

class Menu {
private:
    int selection;
    
public:
    // constructor
    Menu();
    
    // helper functions
    void show_menu();
    int prompt_for_selection();
    int last_selection();
};

#endif /* menu_h */