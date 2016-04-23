//
//  Menu.cpp
//  myBudgetApp
//
//  Created by lindsey anne on 4/21/16.
//  Copyright © 2016 Lindsey Hogg. All rights reserved.
//

#include <iostream>
#include "Menu.hpp"

using namespace std;

Menu::Menu(){
    selection = 1;
}

void Menu::show_menu(){
    cout << "SELECT AN OPTION:" << endl;
    cout << "1. Show budget" << endl;
    cout << "2. Make Deposit" << endl;
    cout << "3. Make Withdrawal" << endl;
    cout << "0. EXIT" << endl;
}

int Menu::prompt_for_selection(){
    cout << "Enter your selection: ";
    cin >> selection;
    cin.ignore();
    return selection;
}

int Menu::last_selection(){
    return selection;
}
