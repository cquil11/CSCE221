#pragma once

#include "HashTable.h"
#include "Hash.h"
#include <string>
#include <vector>

using std::vector;

class ChainingHashTable
{
private:
    vector<vector<Cell<std::string, int>>> table;
    unsigned capacity;

public:
    ChainingHashTable();
    ChainingHashTable(unsigned capacity);
    ~ChainingHashTable();

    unsigned int hash(std::string key);
    void insert(std::string key, int val);
    int remove(std::string key);
    int get(std::string key);
    void printAll(std::string filename);
    int operator[](std::string key);
};