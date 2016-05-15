/*************************************
 * Lindsey Hogg
 * lhogg@mail.sfsu.edu
 * myBudgetApp
 * menu.cpp
 *************************************/

#include <iostream>
#include "menu.h"

using namespace std;

Menu::Menu(){
    selection = 1;
}

void Menu::show_menu(){
    cout << "SELECT AN OPTION:" << endl;
    cout << "1. Show budget" << endl;
    cout << "2. Make deposit" << endl;
    cout << "3. Make withdrawal" << endl;
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
