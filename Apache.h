//
// Created by dorbi on 03/03/2024.
//

#ifndef EX3_APACHE_H
#define EX3_APACHE_H
#include "Plain_Horse.h"

class Apache:public Plain_Horse{
public:
    Apache(string& name,int local): Plain_Horse(name,local){};
    int getC()const override; //"constant offenses" of Apache
    int calculate(int numberRoute) override; //calculate if the horse move or not
    ~Apache() override =default;
};


#endif //EX3_APACHE_H
