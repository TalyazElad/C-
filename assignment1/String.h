//* Assignment: 1
//Author: Yael Bitton , ID: 206888661
//Author: Elad Talyaz , ID: 315326520
//*
//
// Created by eladtalyaz on 13/12/2020.
//

#ifndef INC_12_STRING_H
#define INC_12_STRING_H
#include <iostream>

class String {
private:
    char newStr[10];
    int l;
public:
    String();
    ~String();
    String(char *art);
    void updateValue(char *art);
    bool setCharAt(char *newletter, int idx);
    bool setCharsByUser();
    char getCharAt(int idx);
    void printValue();
    void printValue(bool TrueOrFalse);

};
#endif //INC_12_STRING_H
