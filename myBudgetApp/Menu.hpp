//
//  Menu.hpp
//  myBudgetApp
//
//  Created by lindsey anne on 4/21/16.
//  Copyright © 2016 Lindsey Hogg. All rights reserved.
//

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