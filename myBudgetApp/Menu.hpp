/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * Menu.hpp
 *************************************/

#ifndef Menu_hpp
#define Menu_hpp

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

#endif /* Menu_hpp */