//* Assignment: 1
//Author: Yael Bitton , ID: 206888661
//Author: Elad Talyaz , ID: 315326520
//*
//
// Created by eladtalyaz on 12/12/2020.
//

#ifndef INC_12_TWODIGITS_H
#define INC_12_TWODIGITS_H


class TwoDigits{
private:
    int SecondNum;
    int x,y;
public:
    TwoDigits();
    TwoDigits(char* SeconDigit,char* FirstDigit);
    TwoDigits(int Num);
    void value();
    void update(int z);
    void printValue();

    int FirstNum;
};


#endif //INC_12_TWODIGITS_H
