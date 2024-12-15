//
// Created by dorbi on 16/02/2024.
//

#ifndef EX3_OFERSHIR_LINKEDLIST_H
#define EX3_OFERSHIR_LINKEDLIST_H
#include <iostream>
/**
 * @brief A template class representing a node in a linked list.
 * @tparam T The type of data stored in the node.
 */
template <class T>
class Node {
public:
    T* type; /**< Pointer to the data stored in the node. */
    Node* next; /**< Pointer to the next node in the linked list. */

    /**
     * @brief Constructor for the Node class.
     * @param type Pointer to the data to be stored in the node.
     */
    explicit Node(T* type): type(type), next(nullptr) {}
};

/**
 * @brief A template class representing a linked list.
 * @tparam T The type of data stored in the linked list.
 */
template <class T>
class Linkedlist {
public:
    /**
     * @brief Constructor for the Linkedlist class.
     * Initializes the head and tail pointers to nullptr.
     */
    Linkedlist<T>(): head(nullptr), tail(nullptr) {}

    /**
     * @brief Getter function to retrieve the head pointer of the linked list.
     * @return Pointer to the head node of the linked list.
     */
    Node<T>* getHead();

    /**
     * @brief Inserts a node into the linked list.
     * @param node Pointer to the node to be inserted.
     */
    void insert(T* node);

    /**operator = */
    Linkedlist<T>& operator=(const Linkedlist& other);

    /** copy ctor */
    Linkedlist<T> (const Linkedlist& other);
    /**
     * @brief Destructor for the Linkedlist class.
     * Deallocates memory used by the linked list nodes.
     */
    ~Linkedlist<T>();

private:
    Node<T>* head; /**< Pointer to the head node of the linked list. */
    Node<T>* tail; /**< Pointer to the tail node of the linked list. */
};

/**
 * @brief Getter function to retrieve the head pointer of the linked list.
 * @tparam T The type of data stored in the linked list.
 * @return Pointer to the head node of the linked list.
 */
template <class T>
Node<T>* Linkedlist<T>::getHead() {
    return head;
}

/**
 * @brief Inserts a node into the linked list.
 * @tparam T The type of data stored in the linked list.
 * @param node Pointer to the node to be inserted.
 */
template <class T>
void Linkedlist<T>::insert(T* node) {
    Node<T> *t(new Node<T>(node));
    if (this->head == nullptr)
        this->head = this->tail = t;
    else {
        this->tail->next = t;
        this->tail = t;
    }
}

// Copy constructor
template <class T>
Linkedlist<T>::Linkedlist(const Linkedlist& other) {
    // Initialize head and tail pointers to nullptr
    head = tail = nullptr;
    // Iterate through the other linked list
    for (Node<T>* current = other.head; current != nullptr; current = current->next) {
        // Insert each node's data into this linked list
        insert(new T(*current->type));
    }
}

// Assignment operator
template <class T>

Linkedlist<T>& Linkedlist<T>::operator=(const Linkedlist& other) {
        if (this != &other) {
            Node<T>* current = head;
            while (current != nullptr) {
                Node<T>* temp = current;
                current = current->next;
                delete temp->type;
                delete temp;
            }
            head = tail = nullptr;

            for (Node<T>* curr = other.head; curr != nullptr; curr = curr->next) {
                insert(new T(*curr->type));
            }
        }
        return *this;
}
/**
 * @brief Destructor for the Linkedlist class.
 * @tparam T The type of data stored in the linked list.
 * Deallocates memory used by the linked list nodes.
 */
template <class T>
Linkedlist<T>::~Linkedlist() { // Deallocate memory used by the graph
    Node<T>* temp = this->head;
    while (temp != nullptr) {
        Node<T>* next = temp->next;
        delete temp->type;
        delete temp;
        temp = next;
    }
}

#endif //EX3_OFERSHIR_LINKEDLIST_H
