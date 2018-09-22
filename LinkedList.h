#ifndef MPOINTER_LINKEDLIST_H
#define MPOINTER_LINKEDLIST_H
#include "Node.h"

template <class T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList();
    ~LinkedList();
    void addAtFront(Node<T>* n);
    bool isEmpty();
    void addAtEnd(Node<T>* n);
    Node<T>* getLastNode();
    Node<T>* search(T var);
    Node<T>* deleteNode(T var);
    void printList();
};


#endif //MPOINTER_LINKEDLIST_H
