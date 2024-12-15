//
// Created by dorbi on 07/03/2024.
//
#include "Navajo.h"

int Navajo::getC() const {
    return 4;
}

int Navajo::calculate(int numberRoute) {
    if (numberRoute == 0)return 0;
    return (rand() % numberRoute) + 1;
}
