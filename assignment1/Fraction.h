//* Assignment: 1
//Author: Yael Bitton , ID: 206888661
//Author: Elad Talyaz , ID: 315326520
//*

//
// Created by eladtalyaz on 13/12/2020.
//

#ifndef INC_12_FRACTION_H
#define INC_12_FRACTION_H


class Fraction {
private:
    float up,down;
    float Num ;
public:
    Fraction();
    Fraction(int upper , int downer);
    float Value();
    void updateNumerator(int Newup);
    void updateDenominator(int Newdown);
    void printValue();
};


#endif //INC_12_FRACTION_H
