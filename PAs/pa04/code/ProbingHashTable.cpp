#include "ProbingHashTable.h"
#include <string>
#include <iostream>
#include <fstream>

ProbingHashTable::ProbingHashTable() : capacity(0), table(nullptr) {}

ProbingHashTable::ProbingHashTable(unsigned capacity) : capacity(capacity),
                                                        table(new Cell<std::string, int>[capacity]) {}

ProbingHashTable::~ProbingHashTable() { delete[] table; }

unsigned int ProbingHashTable::hash(std::string key)
{
    return Hash::PRH24(key) % capacity;
}

void ProbingHashTable::insert(std::string key, int val)
{
    unsigned hashIndex = hash(key);

    if (table[hashIndex].key.length() == 0)
    {
        table[hashIndex].key = key;
        table[hashIndex].value = val;
    }
    else if (table[hashIndex].key == key)
    {
        table[hashIndex].value = val;
    }
    else
    {
        unsigned i = 1;
        while (i < capacity)
        {
            if (table[(hashIndex + i) % capacity].key.length() == 0)
            {
                table[(hashIndex + i) % capacity].key = key;
                table[(hashIndex + i) % capacity].value = val;
                break;
            }
            else if (table[(hashIndex + i) % capacity].key == key)
            {
                table[(hashIndex + i) % capacity].value = val;
                break;
            }
            i++;
        }
        if (i == capacity)
            throw std::runtime_error("Error: No cells to add to.");
    }
}

int ProbingHashTable::remove(std::string key)
{
    unsigned hashIndex = hash(key);
    unsigned i = 0;
    while (table[(hashIndex + i) % capacity].key != key && i < capacity)
    {
        i++;
    }
    // Means key was not found
    if (table[(hashIndex + i) % capacity].key != key)
        throw std::runtime_error("Error: key was not found.");

    int val = table[hashIndex + i].value;
    table[(hashIndex + i) % capacity].value = 0;
    table[(hashIndex + i) % capacity].key = "";

    return val;
}

int ProbingHashTable::get(std::string key)
{

    unsigned hashIndex = hash(key);
    if (table[hashIndex].key.length() == 0)
        return 0;
    else if (table[hashIndex].key == key)
        return table[hashIndex].value;
    else
    {

        unsigned i = 0;
        while (table[(hashIndex + i) % capacity].key != key)
        {

            i++;
            // We have searched the whole hash table and not found the key
            if (i == capacity)
                return 0;
        }
        // If the program gets here, we have found the key
        return table[(hashIndex + i) % capacity].value;
    }
}

void ProbingHashTable::printAll(std::string filename)
{
    std::ofstream fileWriter(filename);
    for (int i = 0; i < capacity; i++)
    {
        if (table[i].key.length() != 0)
            fileWriter << table[i].key << " " << table[i].value << std::endl;
    }
}

int ProbingHashTable::operator[](std::string key)
{
    return get(key);
}
