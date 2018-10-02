//
// Created by karla on 02/10/18.
//

#ifndef PROYECTO1_HASHTABLE_H
#define PROYECTO1_HASHTABLE_H

#include <iostream>
#include <vector>
using namespace std;

template<class K, class V>
struct Bucket {
    K key;
    V val;
    Bucket(const K &k, const V &v) : val(v), key(k) {}
};

template<class T> struct myHash {
};

template<> struct myHash<string> {
    static size_t hashFunction(const string& s) {
        return hash<string>()(s);
    }
};

template<> struct myHash<int> {
    static size_t hashFunction(const int m) {
        return hash<int>()(m);
    }
};

template<class K, class V, class HashGenerator = myHash<K> >
class HashTable {
public:
    vector<vector<Bucket<K, V> > > table;
    HashTable(int size) {
        for(int i = 0; i < size; i++) {
            vector<Bucket<K, V> > v;
            table.push_back(v);
        }
    }
    ~HashTable() {}
    void set(const K &k, const V &v) {
        Bucket<K, V> b(k, v);
        for(int i = 0; i < table[hash(k)].size(); i++)
            if(table[hash(k)][i].key == k) {
                table[hash(k)][i] = b;
                return;
            }
        table[hash(k)].push_back(b);
    }
    V get(const K &k) {
        for(int i = 0; i < table[hash(k)].size(); i++)
            if(table[hash(k)][i].key == k)
                return table[hash(k)][i].val;
    }
    bool exist(const K &k) {
        for(int i = 0; i < table[hash(k)].size(); i++)
            if(table[hash(k)][i].key == k)
                return true;
        return false;
    }
    size_t hash(const K &k) {
        return HashGenerator::hashFunction(k) % table.size();
    }
};


#endif //PROYECTO1_HASHTABLE_H
