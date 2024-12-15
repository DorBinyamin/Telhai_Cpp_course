//
// Created by dorbi on 18/02/2024.
//

#ifndef EX3_PLAIN_H
#define EX3_PLAIN_H
#include "Plain_Horse.h"
#include "Apache.h"
#include "Navajo.h"
#include "Cherokee.h"
#include "Path.h"
#include "Intersection.h"

//This department defines the Arava
class Plain{
private:
    unsigned int** Graph; //matrix 2d of length of path
    unsigned int Size; //size of the matrix

public:
    explicit Plain(unsigned int** graph=nullptr,unsigned int size=0);//constructor
    Plain(const Plain& other); //copy ctor
    Plain& operator=(const Plain& other); // // Assignment operator
    void Printplain(Linkedlist<Plain_Horse>* linkedlisthorses,Intersection** intersectionarr,int time);//Print the Arava
    static int count(Linkedlist<Plain_Horse>* linkedlisthorses);// count the size of horses
    void PrintHorses(Linkedlist<Plain_Horse> *linkedlisthorses) const; //this function print all the horses
    void Printlevel_of_paths(Intersection** intersectionarr);    //this function print all level of path like matrix;
   ~Plain();// Destructor

};

#endif //EX3_PLAIN_H

