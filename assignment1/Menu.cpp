//* Assignment: 1
//Author: Yael Bitton , ID: 206888661
//Author: Elad Talyaz , ID: 315326520
//*
//
// Created by eladtalyaz on 13/12/2020.
//

#include "Menu.h"
#include <iostream>
#include "TwoDigits.h"
#include "Fraction.h"
#include "String.h"


Menu::Menu() {return ;}         //default
int Menu::mainMenu() {         // the first menu of selection
    do {
        std::cout << "Choose:\n"
                     "    (1) : TwoDigits func\n"
                     "    (2) : Fractions func\n"
                     "    (3) : String    func\n"
                     "    (4) : Quit          \n" << std::endl;
        std::cin >> c;
        while (c == '\n'){std::cin >> c;}
//            std::cin >> c;

        switch (c) {        // switch what the user choose
            case 1:
                TwoDigitsMenu();
                break;
            case 2:
                FractionMenu();
            case 3:
                StringMenu();
            case 4:
                QuitMenu();
        }

    } while (reinterpret_cast<const char *>(c) != "4");
    return 0 ;
}

int Menu::TwoDigitsMenu() {                        // the menu of the TwoDigits Class
    TwoDigits N1,N2;
    do {
        std::cout << "Choose:\n"
                     "    (1) : update \n"
                     "    (2) : sum \n"
                     "    (3) : print \n"
                     "    (4) : exit \n" << std::endl;
        std::cin >> c;

        switch (c) {                           // switch what the user choose

            case 1:
                int temp;
                std::cout << "enter the new value:" << std::endl;
                std::cin >> temp;
                N1.update(temp);
                break;

            case 2:
                int firstdig , secondig , PlusNum;
                std::cout << "enter the first digit:" << std::endl;
                std::cin >> firstdig;
                std::cout << "enter the second digit:" << std::endl;
                std::cin >> secondig;
                N1.update(firstdig);
                N2.update(secondig);
                PlusNum = N1.FirstNum + N2.FirstNum;
                std::cout << "The sum of "<<firstdig<<"+"<<secondig<<" is: "<<PlusNum << std::endl;
                break;

            case 3:
                std::cout << "First two digit number: ";
                N1.printValue();
                std::cout << "Second two digit number: ";
                N2.printValue();
//                    TwoDigitsMenu();
                break;

            case 4:
                mainMenu();
                break;


        }
//            while (false);
    }while (reinterpret_cast<const char *>(c) != "4");
    return 0 ;
}

int Menu::FractionMenu() {                     // the menu of the Fraction Class
    Fraction N1,N2;
    double NUM;

    do {
        std::cout << "Choose:\n"
                     "    (1) : update upper \n"
                     "    (2) : update downer \n"
                     "    (3) : print \n"
                     "    (4) : sum \n"
                     "    (5) : Exit \n" << std::endl;

//            std::cin >> c;
//            while (c == '\n'){std::cin >> c;}
//            std::cin >> c;
        std::cin >> c;


        switch (c) {                       // switch what the user choose

            case 1:
                int upperdigit;
                std::cout << "enter the upper digit:" << std::endl;
                std::cin >> upperdigit;
                N1.updateNumerator(upperdigit);
                break;
            case 2:
                int downerdigit;
                std::cout << "enter the downer digit:" << std::endl;
                std::cin >> downerdigit;
                N1.updateDenominator(downerdigit);
                break;
            case 3:
                N1.Value();
                N1.printValue();
                break;

            case 4:
                NUM = N1.Value();
                double SumDigit,NewNum;
                std::cout << "enter the number you want to add:" << std::endl;
                std::cin >> SumDigit;
                NewNum = NUM+SumDigit;
                std::cout << "The sum of ";
                std::cout << upperdigit << "/" << downerdigit;
                std::cout<< " and " << SumDigit << " is: " << NewNum <<std::endl;
                break;


            case 5:
                mainMenu();
                break;


        }

    }while (reinterpret_cast<const char *>(c) != "5");
    return 0;
}

char Menu::StringMenu() {                             // the menu of the String Class
    String S1;
    char str[]={};


    do {
        std::cout << "Choose:\n"
                     "    (1) : update string \n"
                     "    (2) : update array \n"
                     "    (3) : update one value in the array \n"
                     "    (4) : value from string \n"
                     "    (5) : print string \n"
                     "    (6) : print lowercase \n"
                     "    (7) : print uppercase \n"
                     "    (8) : Exit \n" << std::endl;

        std::cin >> c;

        switch (c) {                                   // switch what the user choose
            case 1:
                std::cout << "enter the string:" << std::endl;
                std::cin >> str;
                S1.updateValue(str);
                break;

            case 2:
                char* Charin;
                for (int i = 0; i < 9; ++i) {
                    std::cout << "enter the " << i << " char:" << std::endl;
                    std::cin >> Charin;
                    S1.setCharAt(Charin,i);
                }
                S1.setCharAt(NULL,9);
                break;

            case 3:
                int idx;
                std::cout << "enter the char:" << std::endl;
                std::cin >> Charin;
                std::cout << "enter the index:" << std::endl;
                std::cin >> idx;
                if (idx > 9){std::cout << "Error! invalid Index!" << std::endl; break;}
                S1.setCharAt(Charin,idx);
                break;

            case 4:
                char Letter;
                std::cout << "enter the wanted index:" << std::endl;
                std::cin >> idx;
                Letter = S1.getCharAt(idx);
                std::cout << "The value in index " << idx << "is:"<< "'" << Letter << "'." << std::endl;
                break;

            case 5:
                S1.printValue();
                break;

            case 6:
                S1.printValue(0);
                break;

            case 7:
                S1.printValue(1);
                break;

            case 8:
                mainMenu();
                break;

        }


    } while (reinterpret_cast<const char *>(c) != "8");
    return 0;
}
void Menu::QuitMenu()                                  // break and say bye !
{
    std::cout<<"Goodbye"<<std::endl;
    exit(0) ;
}