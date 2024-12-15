//
// Created by dorbi on 03/03/2024.
//

#ifndef EX3_CHEROKEE_H
#define EX3_CHEROKEE_H

#include "Plain_Horse.h"

class Cherokee: public Plain_Horse{
public:
    Cherokee(string& name,int local): Plain_Horse(name,local){};
    inline int getC()const override; //"constant offenses" of Cherokee
    int calculate(int numberRoute) override;
    ~Cherokee() override =default;
    };

#endif //EX3_CHEROKEE_H
