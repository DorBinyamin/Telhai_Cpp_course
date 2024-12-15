//
// Created by dorbi on 03/03/2024.
//

#ifndef EX3_MYSTRING_H
#define EX3_MYSTRING_H
#include "Stack.h"
#include <iostream>
class MyString {
private:
    char* s;  // Pointer to C-style string

public:
    MyString() { //defult ctor
        s = new char[1];
        s[0] = '\0';
    }
    // Meaningful constructor - constructs MyString from a C-style string
    explicit MyString(const char* str);

    // Copy constructor - constructs a copy of MyString
    MyString(const MyString& other);

    // Copy assignment operator - assigns the value of another MyString
    MyString& operator=(const MyString& other);

    // Destructor - cleans up dynamically allocated memory
    ~MyString();


    // Friend function to overload the == operator for equality comparison
    friend bool operator==(const MyString& lhs, const MyString& rhs);


};


#endif //EX3_MYSTRING_H
