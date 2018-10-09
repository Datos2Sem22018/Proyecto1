//
// Created by zuckerberg on 02/10/18.
//

#ifndef MPOINTER_INIT_HASHTABLE_H
#define MPOINTER_INIT_HASHTABLE_H
#include "HashEntry.h"
const int tableSize = 127;

template <class T>
class HashTable {
private:
    HashEntry **table;
public:
    HashTable();
    int hashFunc(T value);
    void insert(T value);
    HashEntry* search(T value);
    void remove(T value);
};

template <class T>
HashTable<T>::HashTable() {
    table = new HashEntry*[tableSize];
    for (int i = 0; i < tableSize; ++i) {
        table[i] = NULL;
    }
}

template <class T>
int HashTable<T>::hashFunc(T value) {
    int key = 0;
    for (unsigned int i = 0; i < value.size(); i++) {
        key += value[i];
    }
    return key % tableSize;

}

template <class T>
void HashTable<T>::insert(T value) {
    int hash = hashFunc(value);
    if (table[hash] == NULL) {
        table[hash] = new HashEntry(value);
    }
}

template <class T>
HashEntry<T>* HashTable<T>::search(T value) {
    int hash = hashFunc(value);
    if (table[hash] == NULL) {
        return NULL;
    } else {
        return table[hash];
    }
}

template <class T>
void HashTable<T>::remove(T value) {
    int hash = hashFunc(value);
    if (table[hash] == NULL) {
        cout << "No element found" << endl;
    } else {
        table[hash] = NULL;
        cout << "Element destroyed" << endl;
    }
}

#endif //MPOINTER_INIT_HASHTABLE_H
