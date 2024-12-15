//
// Created by dorbi on 18/02/2024.
//
#include "ReadFile.h"

using namespace std;

ReadFile::ReadFile(const char* File1, const char* File2) : file1(File1), file2(File2) {
    ifstream inputfile1(file1);  // Open the first file for reading
    if (!Fileok(inputfile1)) {Error(inputfile1);
        return;}
    // Read the size of the matrix from the first line of the file
    string line;
    getline(inputfile1, line);
    unsigned int size = stoi(line);
    if (size <= 0) { // Check if size is valid
        Error(inputfile1);
        return;
    }
    // Allocate memory for the matrix
    unsigned int **matrix = new unsigned int *[size];
    for (unsigned int k = 0; k < size; k++)
        matrix[k] = new unsigned int[size];
    if(!(Chackmatrix(matrix,inputfile1,line,size))){
        Error(inputfile1);
        return;
     }
    inputfile1.close();// Close the first file
    Linkedlist<Plain_Horse> *horses = ReadFile::ReadHorse(file2);  // Read additional data from the second file
    if (horses == nullptr) {// Check if horses data is valid
        deletematrix(matrix, size);
        return;
    }
    Plainplay(horses, matrix, size); // Further processing with horses and matrix data
}



Linkedlist<Plain_Horse>* ReadFile::ReadHorse(const char* file) {
    ifstream inputfile2(file);
    if (!Fileok(inputfile2)) {
        Error(inputfile2);
        return nullptr;
    }//check if the file ok
    Linkedlist<Plain_Horse> *horses = new Linkedlist<Plain_Horse>;
    std::string line,element;
    int location=0;
    while (std::getline(inputfile2, line)) {
        std::istringstream iss(line);
        getline(iss,line,':');
        istringstream (line)>>location;
        while (std::getline(iss,element,',')){
            if(element.length() <= 17 && !(element.empty()))
                if(!Inserttohorses(horses,element,location)){
                    delete horses;
                    return nullptr;
                }
    }}
    return horses;
}


void ReadFile::deletematrix(unsigned int **matrix, unsigned int size) { //free the heap(for matrix)
        for (unsigned int i = 0; i < size; i++)delete matrix[i];
        delete matrix;
}


void ReadFile::Plainplay(Linkedlist<Plain_Horse> *linkedlisthorses, unsigned int **matrix, unsigned int size) {
        // Create an array of Intersection pointers
        Intersection **intersectionarr = new Intersection *[size];
        for (unsigned int i = 0; i < size; i++) {
            intersectionarr[i] = new Intersection();
        }
        for (unsigned int i = 0; i < size; i++) {
            for (unsigned int j = 0; j < size; j++)
                if (matrix[i][j] != 0) intersectionarr[i]->Insert(new Path(static_cast<int>(matrix[i][j]), static_cast<int>(j) + 1));
        }
        Plain *plain = new Plain(matrix, size);// Create a Plain object
        int time;
        cin >> time;// Prompt the user for input
        plain->Printplain(linkedlisthorses, intersectionarr, time); // Print the plain play based on the user input
        deleteintersection(intersectionarr, size); // Clean up memory
        delete plain; // Clean up memory
    }


void ReadFile::deleteintersection(Intersection **intersectionarr,unsigned int size) { //free the heap(for int intersectionarr)
        for (unsigned int i = 0; i < size; i++)delete intersectionarr[i];
        delete intersectionarr;
    }


bool ReadFile::Fileok(ifstream &inputfile) {
        if (!inputfile.is_open()) {
            return false;
        }
        return true;
    }


void ReadFile::Error(ifstream &inputfile) {
        cerr << "ERROR: invalid input.\n";
        inputfile.close();
    }


bool ReadFile::Chackmatrix(unsigned int **matrix, ifstream &inputfile, string &line, unsigned int size) {
        unsigned int i = 0, j;
        while (std::getline(inputfile, line)) {
            std::istringstream iss(line);
            string length;
            j=0;
            while (getline(iss, length, ' ')) {
                matrix[i][j] = stoi(length);
                if (i == j && matrix[i][j] != 0) {// Error handling for non-zero diagonal elements
                    deletematrix(matrix, size);
                    return false;
                }j++;
            }// Check if number of elements in a row matches size
            if (j != size) {
                deletematrix(matrix, size);
                return false;
            }i++;
        }
        if (i != size) {// Check if number of rows matches size
            deletematrix(matrix, size);
            return false;
        }
        return true;
    }


bool ReadFile::Inserttohorses(Linkedlist<Plain_Horse> *horses, string& name,int & number) {
    switch (name[0]) {
        case 'A':
            horses->insert(new Apache(name, number));
            break;
        case 'C':
            horses->insert(new Cherokee(name, number));
            break;
        case 'N':
            horses->insert((new Navajo(name, number)));
            break;
        default:
            return false;
    }
    return true;
}






