//* Assignment: 1
//Author: Yael Bitton , ID: 206888661
//Author: Elad Talyaz , ID: 315326520
//*

// Created by eladtalyaz on 13/12/2020.
//
#include <iostream>
#include "Fraction.h"

Fraction::Fraction() { up = 0 ; down = 1;}   //default
Fraction::Fraction(int upper , int downer) { up = upper ;  down = downer;}  //the num if we enter 2 int numbers
float Fraction::Value()                                                     // update the num.(checks for 0 and etc.)
{
    if(down == 0){up = 0; down = 1;}
    if (up < 0 && down < 0 || up > 0 && down < 0){up = -up ; down = -down;}
    Num = up / down;

    return Num;
}
void Fraction::updateNumerator(int Newup){up = Newup; Value();}                    // update the numerator
void Fraction::updateDenominator(int Newdown){down = Newdown; Value();}           // update the denominator
void Fraction::printValue()                                                      // print !!
{
    std::cout << up << "/" << down << std::endl;
}