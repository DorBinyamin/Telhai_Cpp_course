//
// Created by dorbi on 18/02/2024.
//
#include "Path.h"
/**< The docstring and explain all function in file path.h but I explain the operator ++ */
int Path::getTo() const {
    return to;
}

double Path::getTransitionLevel() const {
    return transition_level;
}

void Path::setTransitionLevel(double transitionLevel) {
    this->transition_level = transitionLevel;
}


// Assignment operator
Path& Path::operator=(const Path &other) {
    if (this != &other) {
        level_of_path = other.level_of_path;
        to = other.to;
        transition_level = other.transition_level;
    }
    return *this;
}

double Path::operator+(double c) const{
    return this->transition_level+(c/level_of_path);
}


