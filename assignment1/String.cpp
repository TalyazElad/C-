//* Assignment: 1
//Author: Yael Bitton , ID: 206888661
//Author: Elad Talyaz , ID: 315326520
//*
//
// Created by eladtalyaz on 13/12/2020.
//

#include <iostream>
#include "String.h"


String::String(): newStr(){};                       //default
String::~String() {}                                // distractor

String::String(char art[]) {                          // gets a string if its bigger then 9 it will take only 9 max
    for (l = 0; art[l] != '\0'; l++) {}              //check the size of the art
    int size = l;
    if (size >= 10) {
        for (int i = 0; i < 10; i++) {
            newStr[i] = art[i];
        }
        newStr[9] = '\0';
    } else {
        for (int i = 0; i < size; i++) {
            newStr[i] = art[i];
        }
        newStr[size] = '\0';
    }

}

void String::updateValue(char art[]) {                // update the string !
    for (l = 0; art[l] != '\0'; l++) {}              //check the size of the art
    int size = l;
    if (size >= 10) {
        for (int i = 0; i < 10; i++) {
            newStr[i] = art[i];
        }
        newStr[9] = '\0';
    } else {
        for (int i = 0; i < size; i++) {
            newStr[i] = art[i];
        }
        newStr[size] = '\0';
    }
}

bool String::setCharAt(char *newletter, int idx) {      // changes the letter by its index
    if (idx > 8) { return 0; }
    else if (newStr[idx] == '\0') {
        newStr[idx] = *newletter;
        newStr[idx + 1] = '\0';
    } else { newStr[idx] = *newletter; }
    return 1;
}

bool String::setCharsByUser() {                         // the user says what index he want to change
    int temp = 1, counter = 0;
    int *idxs = new int;
    int idx;
    char *letter = new char;
    for (l = 0; newStr[l] != '\0'; l++) {}              //check the size of the art
    int size = l;
    while (temp) {
        std::cout << "the letter is :" << std::endl;
        std::cin >> letter;
        std::cout << "the idx is :" << std::endl;
        std::cin >> idx;
        if (idx > size - 1) { return 0; }
        *idxs = idx;
        std::cout << "do you want to change another one ? (1/0)" << std::endl;
        std::cin >> temp;
        if (temp == 1) {
            letter++;
            idxs = idxs + 4;
        }
        counter++;
    }
    for (int i = 0; i < counter; ++i) {
        setCharAt(letter, *idxs);
        letter--;
        idxs = idxs - 4;
    }
    return 1;
}

char String::getCharAt(int idx) {                        // the user says what index he want to see as a letter
    for (l = 0; newStr[l] != '\0'; l++) {}              //check the size of the art
    int size = l;
    const char err[2] = "-";
    if (idx > size) {
        std::cout << "there is no such value" << std::endl;
        return err[2];
    }
    char temp = newStr[idx];
    return temp;
}

void String::printValue() {                              // print !!
    for (l = 0; newStr[l] != '\0'; l++) {}              //check the size of the art
    int size = l;
    for (int i = 0; i < size; i++) {
        std::cout << newStr[i];
        if (i == size - 1) { std::cout << std::endl; }
    }
}

void String::printValue(bool TrueOrFalse) {              // print by the user request (upper/lower case)
    for (l = 0; newStr[l] != '\0'; l++) {}              //check the size of the art
    int size = l;
    if (TrueOrFalse == 1) {
        for (int i = 0; i < size; ++i) {
            if (newStr[i] > 96) {
                newStr[i] = newStr[i] - 32;
            }

        }
    } else {
        for (int i = 0; i < size; ++i) {
            if (newStr[i] < 91) {
                newStr[i] = newStr[i] + 32;
            }
        }

    }
    printValue();
}