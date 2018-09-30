#ifndef MPOINTER_NODE_H
#define MPOINTER_NODE_H
#include <iostream>
/**
 * Clase Nodo, utilizada para almacenar
 * @tparam T
 */
template <class T>
class Node {
public:
    T data;/** variable que almacena el valor a agregar en la lista**/
    Node* next; /**referencia al siguietne nodo**/
    Node<T> (T var);/**Constructor de la clase **/
};
/**
 * Constructor de la clase Nodo
 * @tparam T
 * @param var : valor a almacenar
 */
template <class T>
Node<T>::Node(T var) {
    this->data = var;
    this->next = nullptr;
}


#endif //MPOINTER_NODE_H
