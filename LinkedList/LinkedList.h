#ifndef MPOINTER_LINKEDLIST_H
#define MPOINTER_LINKEDLIST_H
#include "Node/Node.h"

template <class T>
class LinkedList {
public:
    Node<T>* head;
    void addAtFront(Node<T>* n);
    bool isEmpty();
    void addAtEnd(Node<T>* n);
    Node<T>* getLastNode();
    Node<T>* search(T var);
    Node<T>* deleteNode(T var);
    void printList();
    LinkedList();
    ~LinkedList();

};


#endif //MPOINTER_LINKEDLIST_H
