//
// Created by dorbi on 03/03/2024.
//
#include "MyString.h"
#include <cstring>


// Meaningful constructor - constructs MyString from a C-style string
MyString::MyString(const char* str) {
    s = new char[strlen(str) + 1];
    strcpy(s, str);
}

// Copy constructor - constructs a copy of MyString
MyString::MyString(const MyString& other) {
    s = new char[strlen(other.s) + 1];
    strcpy(s, other.s);
}

// Copy assignment operator - assigns the value of another MyString
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] s;
        s = new char[strlen(other.s) + 1];
        strcpy(s, other.s);
    }
    return *this;
}

// Destructor - cleans up dynamically allocated memory
MyString::~MyString() {
    delete[] s;
}


// Friend function to overload the == operator for equality comparison
bool operator==(const MyString& lhs, const MyString& rhs) {
    return strcmp(lhs.s, rhs.s) == 0;
}


