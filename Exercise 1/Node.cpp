#include "Node.h"


Node::Node(int factorial, Node *next) : factorial(factorial), next(next) {}//constructor

int Node::getFactorial() const {//Returns the rally number
    return factorial;
}



Node* Node::getNext() const {//Returns the following address
    return next;
}

void Node::setNext(Node *nextnew) {//Changes the following address
    Node::next = nextnew;
}


Node::~Node()= default;//Destructor
