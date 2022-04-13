#include "ProbingHashTable.h"
#include <string>
#include <iostream>

ProbingHashTable::ProbingHashTable() : capacity(0), table(nullptr) {}

ProbingHashTable::ProbingHashTable(unsigned capacity) : capacity(capacity),
                                                        table(new Cell<std::string, int>[capacity]{}) {}

ProbingHashTable::~ProbingHashTable() { delete[] table; }

unsigned int ProbingHashTable::hash(std::string key)
{
    return Hash::PRH24(key) % capacity;
}

void ProbingHashTable::insert(std::string key, int val)
{
    // unsigned hashIndex = hash(key);
    // if (table[hashIndex].key == key)
}

int ProbingHashTable::remove(std::string key)
{
}

int ProbingHashTable::get(std::string key)
{
    unsigned hashIndex = hash(key);
    if (table[hashIndex].key == key)
        return table[hashIndex].value;
    else
    {
        unsigned i = 0;
        while (table[hashIndex + i].key != key)
        {
            i = (i + 1) % capacity;
            // We have searched the whole hash table and not found the key
            if (i == capacity)
                return 0;
        }
        // If the program gets here, we have found the key
        return table[hashIndex + i].value;
    }
}

void ProbingHashTable::printAll(std::string filename)
{

}
