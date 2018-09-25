#ifndef MPOINTER_LINKEDLIST_H
#define MPOINTER_LINKEDLIST_H
#include "Node/Node.h"

template <class T>
class LinkedList {
public:
    int size;
    Node<T>* head;
    bool isEmpty();
    void setValue(T var, int pos);
    void add(T var);
    void remove(int pos);
    Node<T>* getNode(int pos);
    Node<T>* getLastNode();
    Node<T>* search(T var);
    T get(int i);
    Node<T>* deleteNode(T var);
    void printList();
    LinkedList();
    ~LinkedList() = default;

};

template <class T>
LinkedList<T>::LinkedList() {
    head = NULL;
    size = 0;
}

template <class T>
void LinkedList<T>::setValue(T var, int pos) {
    getNode(pos)->data = var;
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
T LinkedList<T>::get(int i){
    Node<T>* ptr = head;
    int x = 0;
    while(x != i){
        ptr = ptr->next;
        x++;
    }if(ptr == nullptr){
        return NULL;
    }
    return ptr->data;
}

template <class T>
Node<T>* LinkedList<T>::getNode(int pos)
{
    Node<T>* aux = head;
    int x = 0;
    while (x != pos) {
        aux = aux->next;
        x++;
    }
    if (aux == NULL) {
        return NULL;
    }
    return aux;
}

template<class T>
void LinkedList<T>::add(T var) {
    if (size == 0) {
        Node<T>* aux = new Node<T>(var);
        head = aux;
        head->next = NULL;
        size++;
    } else {
        Node<T>* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        Node<T>* aux = new Node<T>(var);
        aux->next = NULL;
        current->next = aux;
        size++;
    }
}

template <class T>
void LinkedList<T>::remove(int pos){
    int pos_aux = pos;
    Node<T>* current = head;
    if (pos_aux == 0) {
        head = current->next;
        size -= 1;
    } else if (pos_aux == size - 1) {
        while (current->next->next != NULL) {
            current = current->next;
        }
        current->next = NULL;
        size -= 1;
    } else if (pos_aux >= size) {
        std::cout<<"No se encuentra el elemento"<< std::endl;
    } else {
        int b = 0;
        while (pos_aux - 1 != b) {
            current = current->next;
            b++;
        }
        current->next = current->next->next;
        size -= 1;
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
