//* Assignment: 1
//Author: Yael Bitton , ID: 206888661
//Author: Elad Talyaz , ID: 315326520
//*
//
// Created by eladtalyaz on 13/12/2020.
//

#ifndef INC_12_MENU_H
#define INC_12_MENU_H
#include <iostream>
#include "TwoDigits.h"
#include "Fraction.h"
#include "String.h"

class Menu {
public:
    int c;
    Menu();
    int mainMenu();
    int TwoDigitsMenu();
    int FractionMenu();
    char StringMenu();
    void QuitMenu();
};



#endif //INC_12_MENU_H
