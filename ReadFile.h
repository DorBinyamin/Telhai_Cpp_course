//
// Created by dorbi on 18/02/2024.
//

#ifndef EX3_READFILE_H
#define EX3_READFILE_H
#include "Plain.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Plain_Horse.h"
#include "Apache.h"
#include "Navajo.h"
#include "Cherokee.h"
#include "Linkedlist.h"
#include "Intersection.h"

class ReadFile {
private:
    const char *file1;
    const char *file2;

public:
    ReadFile(const char *File1, const char *File2); //ctor
    static Linkedlist<Plain_Horse>* ReadHorse(const char* file1); //read from the file the list of horses
    static void Plainplay(Linkedlist<Plain_Horse>* linkedlisthorses,unsigned int** graph,unsigned int size);//if the files is ok so this function input from the user c and time and start the game(Arava)
    static void deletematrix(unsigned int** matrix,unsigned int size);//free all the memory from the heap(for matrix 2D)
    static void deleteintersection(Intersection** intersectionarr,unsigned int size);//free all the memory from the heap
    static bool Fileok(ifstream& inputfile);
    static void Error(ifstream& inputfile);
    static bool Inserttohorses(Linkedlist<Plain_Horse>* linkedlisthorses,string& name,int& number);
    static bool Chackmatrix(unsigned int **matrix,ifstream& inputfile,string& line,unsigned int size);
    ~ReadFile()=default;
};

#endif //EX3_READFILE_H
/**Note to the reviewer:I didn't need to use all the big three because copying is the copying of primitive variables and the default is enough for me*/

