//
// Created by dorbi on 07/03/2024.
//
#include "Intersection.h"
Intersection::Intersection(): sizeofPaths(0) {
    paths = new Linkedlist<Path>();
}

void Intersection::Insert(Path* path) {
paths->insert(path);
sizeofPaths++;
}


Linkedlist<Path>* Intersection::getPaths() const {
    return paths;
}

Intersection& Intersection::operator=(const Intersection& other) {
    if (this != &other) {
        sizeofPaths = other.sizeofPaths;
        delete paths; // Deallocating existing memory
        paths = new Linkedlist<Path>(*other.paths); // Copying the linked list
    }
    return *this;
}

int Intersection::getSizeofpaths() const {
    return sizeofPaths;
}

Intersection::~Intersection() {
    delete paths;
}

