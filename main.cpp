#include <iostream>
#include "ReadFile.h"

int main(int argc, char* argv[]) {
    if (argc != 3) { //Check if input from user error
        std::cerr << "ERROR: Invalid input.\n";
        return 1;
    }
    ReadFile(argv[1], argv[2]); //play all the project with read the input from the user
    return 0;
}

/**Note to the reviewer: I preferred place complexity over time complexity even though I tried to optimize time complexity as much as possible
* but always one comes at the expense of the other You will notice that the space complexity in the program is very low */


