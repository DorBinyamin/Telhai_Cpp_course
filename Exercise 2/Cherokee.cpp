//
// Created by dorbi on 07/03/2024.
//
#include "Cherokee.h"


int Cherokee::calculate(int numberRoute) { //calculate if the horse move or not
    int rnd = rand() % 2;
    if(numberRoute == 0 || rnd == 0)
        return 0;
    return (rand() % numberRoute)+1;
}

int Cherokee::getC() const { //"constant offenses" of Cherokee
    return 3;
}
