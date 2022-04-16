#include "ProbingHashTable.h"

#include <string>
#include <iostream>
#include <fstream>

ProbingHashTable::ProbingHashTable() : capacity(0), table(nullptr) {}

ProbingHashTable::ProbingHashTable(unsigned capacity) : capacity(capacity),
                                                        table(new Cell<std::string, int>[capacity]) {}

ProbingHashTable::~ProbingHashTable() { delete[] table; }

/**
 * @brief Applies PRH24 hash function to a given string
 *
 * @param key string key
 * @return unsigned int integer representation of key as a hashed value
 */
unsigned int ProbingHashTable::hash(std::string key)
{
    return Hash::PRH24(key) % capacity;
}

/**
 * @brief Inserts a given key value pair into the hash table. If there is a collision at
 * the specified index, Cell is simply added to the next available index
 *
 * @param key string key to be added
 * @param val int val to be added
 */
void ProbingHashTable::insert(std::string key, int val)
{
    unsigned hashIndex = hash(key);

    // If the index is empty, we just add the Cell at the index
    if (table[hashIndex].key.length() == 0)
    {
        table[hashIndex].key = key;
        table[hashIndex].value = val;
    }
    // If data exists at the index with the same key as specified, we override the existing data
    else if (table[hashIndex].key == key)
    {
        table[hashIndex].value = val;
    }
    // Otherwise, we search for the next available cell (that is, either empty or with data that
    // has the same key as specified) and then add the data there
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
        // If we have searched every spot in the table and there were no available spots,
        // we throw a runtime error because the table is at full capacity
        if (i == capacity)
            throw std::runtime_error("Error: No cells to add to.");
    }
}

/**
 * @brief Given a key (and thus a hashed index), remove the Cell at that index
 *
 * @param key string key to be removed
 * @return int value of the removed Cell
 */
int ProbingHashTable::remove(std::string key)
{
    unsigned hashIndex = hash(key);
    unsigned i = 0;
    // The table is searched until we reach an index where data exists that equals the key
    // specified OR we have searched every element and not found the key specified
    while (table[(hashIndex + i) % capacity].key != key && i < capacity)
    {
        i++;
    }
    // Means key was not found
    if (table[(hashIndex + i) % capacity].key != key)
        throw std::runtime_error("Error: key was not found.");
    // If we got to this point, they key was found at index = (hashIndex + i) % capacity
    // so we clear the data at that index
    int val = table[hashIndex + i].value;
    table[(hashIndex + i) % capacity].value = 0;
    table[(hashIndex + i) % capacity].key = "";

    // Return the value removed
    return val;
}

/**
 * @brief Given a key, return its corresponding value
 *
 * @param key string key to be found
 * @return int value of the key
 */
int ProbingHashTable::get(std::string key)
{
    unsigned hashIndex = hash(key);
    // If the key at the hashIndex is empty, we know the key cannot exist so we return 0
    if (table[hashIndex].key.length() == 0)
        return 0;
    // If data exists at the given hashIndex with the same key value, we return that value
    else if (table[hashIndex].key == key)
        return table[hashIndex].value;
    // Otherwise, we search the indices succeeding the original hashIndex until we either
    // find the specified key or search all possible indices, in which case we return 0 
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

/**
 * @brief Prints all existing elements of the chaining hash table to an output file
 *
 * @param filename name of the output file
 */
void ProbingHashTable::printAll(std::string filename)
{
    std::ofstream fileWriter(filename);
    for (int i = 0; i < capacity; i++)
    {
        if (table[i].key.length() != 0)
            fileWriter << table[i].key << " " << table[i].value << std::endl;
    }
}

/**
 * @brief Overloaded subscript operator 
 * 
 * @param key string key to be found
 * @return int corresponding integer value at hash(key) index
 */
int ProbingHashTable::operator[](std::string key)
{
    return get(key);
}
