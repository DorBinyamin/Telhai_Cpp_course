//
// Created by dorbi on 03/03/2024.
//

#ifndef EX3_NAVAJO_H
#define EX3_NAVAJO_H
#include "Plain_Horse.h"

class Navajo:public Plain_Horse{
public:
    Navajo(string& name,int local): Plain_Horse(name,local){};
    int getC()const override;//"constant offenses" of Navajo
    int calculate(int numberRoute) override; //calculate if the horse move or not
    ~Navajo() override =default;

};
#endif //EX3_NAVAJO_H
