//
// Created by dorbi on 03/03/2024.
//

#ifndef EX3_PLAIN_HORSE_H
#define EX3_PLAIN_HORSE_H
#include <iostream>Exercise 2


//abstract class Plain_horse
using namespace std;
class Plain_Horse{
private:
    string name;
    int location;
public:
    Plain_Horse(string& str,int local):name(str),location(local){}; //ctor
    Plain_Horse(const Plain_Horse& other)= default; //copy ctor
    int getLocation()const;
    string getName()const;
    void setLocation(int local);
    virtual int getC()const=0; //get the "constant offenses".
    virtual int calculate(int numberRoute)=0;
    Plain_Horse& operator=(const Plain_Horse& other);
    virtual  ~Plain_Horse()=default;
};
#endif //EX3_PLAIN_HORSE_H
