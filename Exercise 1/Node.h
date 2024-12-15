//
// Created by dorbi on 31/01/2024.
//

#ifndef EX1_NODE_H
#define EX1_NODE_H
class Node{
public:

    explicit Node(int factorial=0, Node *next= nullptr);//constructor
    int getFactorial() const;//Returns the rally number
    Node *getNext() const ;//Returns the following address
    void setNext(Node *next);//Changes the following address
    ~Node();//Destructor



private:
    int factorial;//present the number of factorial
    Node* next;


};
#endif //EX1_NODE_H
