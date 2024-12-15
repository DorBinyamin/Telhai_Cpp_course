
#include <iostream>
#include "linkedList.h"
using namespace std;

int main(int argc,char* argv[]) {
    if(argc < 3){
        cerr<<"Invalid arguments <int><int>.\n";//Checks if the number of values we received is correct
        return  0;
    }
    const int n = stoi(argv[1]),max =  stoi(argv[2]);//Enters the values we received from the user in 2 variables that represent the size of the promatation and the maximum amount of promatations that the calculator can contain
    int choice = 0;
    auto *fullarr= new Linkedlist;//Defining the repository that could handle all the permutations
    cout << "[1] Add Permutation" << "\n" << "[2] Add Factorial\n"  << "[3] Push to the Top\n" <<"[4] Print\n" << "[5] Exit" << endl;//Print the menu to the user
    cin >> choice;
    while (choice >=0 || choice <= 0) {//this loop Checked if the number from the user is ok, and call to function that user want
        switch (choice) {
            case 1:
                AddPermutation( max,n,fullarr); //Entering consideration into the system according to the value of the consideration
                break;
            case 2:
                AddFactorial( max, n, fullarr); //Entering consideration into the system according to its assembly representation.
                break;
            case 3:
                PushtotheTop(n,max,fullarr); //Entering consideration into the system based on action on permutations
                break;
            case 4:
                print(fullarr,n); //Print the sequence of permutations entered into the system
                break;
            case 5:               //exit
                delete fullarr;
                return 0;
            default:
                cerr << "Invalid option" << endl;//Error if user enters a number not in the range 1 through 5
                break;
        }
        cin >> choice;//wait to number from the user
    }
}
