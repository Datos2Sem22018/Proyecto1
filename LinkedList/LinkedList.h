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
    ~LinkedList() = default;

};

template <class T>
LinkedList<T>::LinkedList() {
    head = NULL;
}

template <class T>
void LinkedList<T>::addAtFront(Node<T>* n) {
    n->next = head;
    head = n;
}

template <class T>
bool LinkedList<T>::isEmpty() {
    if (head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

template <class T>
void LinkedList<T>::addAtEnd(Node<T>* n) {
    if (head == NULL) {
        head = n;
        n->next = NULL;
    } else {
        Node<T> *n2 = getLastNode();
        n2->next = NULL;
    }
}

template <class T>
Node<T>* LinkedList<T>::getLastNode() {
    Node<T>* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    return ptr;
}

template <class T>
Node<T>* LinkedList<T>::search(T var) {
    Node<T>* ptr = head;
    while (ptr != NULL && ptr->data != var) {
        ptr = ptr->next;
    }
    return ptr;
}

template <class T>
Node<T>* LinkedList<T>::deleteNode(T var) {
    Node<T>* n = search(var);
    Node<T>* ptr = head;
    if (ptr == n) {
        head = n->next;
        return n;
    } else {
        while (ptr->next != n) {
            ptr = ptr->next;
        }
        ptr->next = n->next;
        return n;
    }
}

template <class T>
void LinkedList<T>::printList() {
    Node<T>* ptr = head;
    while (ptr != NULL) {
        std::cout << ptr->data << "; " << std::flush;
        ptr = ptr->next;
    }
}



#endif //MPOINTER_LINKEDLIST_H
