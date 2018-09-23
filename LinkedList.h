#ifndef MPOINTER_LINKEDLIST_H
#define MPOINTER_LINKEDLIST_H
#include "Node.h"

template <class T>
class LinkedList {
public:
    Node* head;
    void addAtFront(Node* n);
    bool isEmpty();
    void addAtEnd(Node* n);
    Node* getLastNode();
    Node* search(T var);
    Node* deleteNode(T var);
    void printList();
    LinkedList();


};


#endif //MPOINTER_LINKEDLIST_H
