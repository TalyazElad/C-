//* Assignment: 1
//Author: Yael Bitton , ID: 206888661
//Author: Elad Talyaz , ID: 315326520
//*
//
// Created by eladtalyaz on 12/12/2020.
//
#include <iostream>
#include "TwoDigits.h"


TwoDigits::TwoDigits() {FirstNum = 0 ; SecondNum = 0 ;}       // default
TwoDigits::TwoDigits(char* SeconDigit,char* FirstDigit) {x = *SeconDigit ; y = *FirstDigit;}  // get nums by char
TwoDigits::TwoDigits(int Num) {y = Num + 48 ; x = 48;}                                        // gets nums as int
void TwoDigits::value()                                     // update the value of the nums by their ascii table value
{
    FirstNum = y-48;
    SecondNum = x-48;
}
void TwoDigits::update(int z)                                   // update the num if it gets as single of int
{
    FirstNum = z;
    SecondNum = 0;
}
void TwoDigits::printValue()                                    // print !!!!
{
    if (SecondNum == 0)
    {
        std::cout <<FirstNum<< std::endl;
    } else
        std::cout << SecondNum << FirstNum << std::endl;
}