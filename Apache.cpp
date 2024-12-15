//
// Created by dorbi on 07/03/2024.
//
#include "Apache.h"

int Apache::getC()const { //"constant offenses" of Apache
    return 2;
}

int Apache::calculate(int numberRoute) { //calculate if the horse move or not
    return (rand() % (numberRoute+1));
}
