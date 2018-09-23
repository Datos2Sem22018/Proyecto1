#include "LinkedList.h"


template <class T>
LinkedList::LinkedList() {
    head = NULL;
}

template <class T>
LinkedList::~LinkedList() {

}

template <class T>
void LinkedList::addAtFront(Node<T>* n) {
    n->next = head;
    head = n;
}

template <class T>
bool LinkedList::isEmpty() {
    if (this->head == nullptr) {
        return 1;
    } else {
        return 0;
    }
}

template <class T>
void LinkedList::addAtEnd(Node<T>* n) {
    if (head == NULL) {
        head = n;
        n->next = NULL;
    } else {
        Node *n2 = getLastNode();
        n2->next = NULL;
    }
}

template <class T>
Node* LinkedList::getLastNode() {
    Node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    return ptr;
}

template <class T>
Node* LinkedList::search(T var) {
    Node* ptr = head;
    while (ptr != nullptr && ptr->data != var) {
        ptr = ptr->next;
    }
}

template <class T>
Node* LinkedList::deleteNode(T var) {
    Node* n = search(var);
    Node* ptr = head;
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
void LinkedList::printList() {
    Node* ptr = head;
    while (ptr != nullptr) {
        std::cout << ptr->data << "; " << std::flush;
        ptr = ptr->next;
    }
}

template<class T>

