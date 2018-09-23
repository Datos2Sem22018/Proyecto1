#include "Node.h"

template <class T>
Node::Node(T var) {
    this->data = var;
    this->next = nullptr;
}
