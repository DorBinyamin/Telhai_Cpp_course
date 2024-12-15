//
// Created by dorbi on 31/01/2024.
//

#ifndef EX1_LINKEDLIST_H
#define EX1_LINKEDLIST_H
#include<iostream>
#include "Node.h"


class Linkedlist{
public:

    Linkedlist():head(nullptr),tail(nullptr),index(nullptr){} ;//constructor
    void insert(int num);//Puts the next member into the array
    Node *getHead() const;//return the head of the list
    bool isEmpty();//chack if the list is empty
    int getelement();//return the "factorial number"
    Node* getCursor();//return the address of cursor
    ~Linkedlist();//Destructor

private:
    Node* head;
    Node* tail;
    Node* index;


};




void AddPermutation( int max, int n,Linkedlist* fullarr);
//The function receives a change from the user in its full representation, converts the integers separated by a comma to an array, and in each of the following situations, the system issues an Invalid permutation.n error message and does not save the transformation.
//The sequence of numbers contains numbers outside the n-1 range
// The sequence is not unique – that is, there exists a number that appears more than once.
// The new consideration is not one legal action away from the last consideration enterd in the case of the first consideration entry,
//She will not check the conditions

void AddFactorial( int max, int n,Linkedlist* fullarr);
//The function receives from the user a number representing a transformation in the base of a factorial and in each
//From the following situations, the function prints an error message:
//Invalid or already exists factorial representation.n
//- The number is not in the valid number range 0-n!
//- The number already exists in the sequence of permutations recorded so far.
//- The consideration represented by this number is not one legal action away from the last consideration entered.
void PushtotheTop( int n, int max,Linkedlist* fullarr);
//The function takes an integer representing the number of the member we want to perform the operation on. and "pushes" the number in the index to the beginning. In any of the following situations, the program prints an Invalid operation or permutation already exists.
//- The resulting number is not within the valid operating range 3 until n.
//- The consideration received after running this operation, already exists in the list of permutations.
void print(Linkedlist* fullarr, int n);
//The function will print to the user a menu that allows selecting the print format
//]1[ Full print
//]2[ Print factorial values only
//]3[ Prints only permutation values
//- Every time you enter a book outside this range, the function prints an error message
//Invalid print option
int arrtofactorial(const int* arr, int n );
// change the array to number (factorial)
int factorial(int n);
//return the number in factorial
std::string factorialtoarr(int num,int n);
//change the number(factorial) to string that container the Permutation
void printall(Node* arr, int n);
//print the Permutation + factorial
void slice(int n,int remove,int*arr);
// "slice" the array and removes the index she received
void printperm(Node* t, int n);
//print only the Permutation
int* stringpermtoarr( int n,std::string &perm);
// Changes the permutation string to an array of int (the array is dynamically assigned)
int pushtothetposucess(const int * arrperm ,  int n,int move);
//The function takes an array and index and pushes the number that appears in the inx at the beginning of the array and moves all other elements to the right if successful,
// returns the factorial value of the permutation
bool checkaction(int * arr,int n,int num);
//Checks if the permutation senses that we got one one action away from the previous one
#endif //EX1_LINKEDLIST_H
