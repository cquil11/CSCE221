#include "ChainingHashTable.h"

#include <string>
#include <iostream>
#include <fstream>

ChainingHashTable::ChainingHashTable() : capacity(0), table(0) {}

ChainingHashTable::ChainingHashTable(unsigned capacity) : capacity(capacity), table(capacity) {}

ChainingHashTable::~ChainingHashTable() {}

/**
 * @brief Applies PRH24 hash function to a given string
 *
 * @param key string key
 * @return unsigned int integer representation of key as a hashed value
 */
unsigned int ChainingHashTable::hash(std::string key)
{
    return Hash::PRH24(key) % capacity;
}

/**
 * @brief Inserts a given key value pair into the hash table. If there is a collision at
 * the specified index, Cell is simply added to the back of the list at the given index.
 *
 * @param key string key to be added
 * @param val int val to be added
 */
void ChainingHashTable::insert(std::string key, int val)
{
    unsigned hashIndex = hash(key);

    // If the vector at the hashIndex is empty, then we can add the new cell at that position
    if (table.at(hashIndex).size() == 0)
        table.at(hashIndex).push_back(Cell<std::string, int>(key, val));
    // Otherwise, loop through the vector at the hashIndex until either we have reached
    // a cell with the same key, in which case we override it's value data member, or we reach a
    // cell with a different key, in which case we add a new Cell to the end of the existing chain
    else
    {
        for (int i = 0; i < table.at(hashIndex).size(); i++)
        {
            if (table.at(hashIndex).at(i).key == key)
            {
                table.at(hashIndex).at(i).value = val;
                return;
            }
            else
            {
                table.at(hashIndex).push_back(Cell<std::string, int>(key, val));
                break;
            }
        }
    }
}

/**
 * @brief Given a key (and thus a hashed index), remove the Cell at that index
 *
 * @param key string key to be removed
 * @return int value of the removed Cell
 */
int ChainingHashTable::remove(std::string key)
{
    unsigned hashIndex = hash(key);
    // Loops through the vector at the given hashIndex until we have reached the cell
    // that holds the same key as the key passed into the function, at which point we remove
    // the indicated cell and return its value
    for (int i = 0; i < table.at(hashIndex).size(); i++)
    {
        if (table.at(hashIndex).at(i).key == key)
        {
            int res = table.at(hashIndex).at(i).value;
            table.at(hashIndex).erase(table.at(hashIndex).begin() + i);
            return res;
        }
    }
    // Got to end of list and did not find key
    return 0;
}

/**
 * @brief Given a key, return its corresponding value
 *
 * @param key string key to be found
 * @return int value of the key
 */
int ChainingHashTable::get(std::string key)
{
    unsigned hashIndex = hash(key);

    // If the chain of Cells at the given hashIndex is empty, the key obviously does
    // not exist so we return 0
    if (table.at(hashIndex).size() == 0)
        return 0;
    // Otherwise, we loop through every element of the chain at the given hashIndex
    // and return the value of a match between the key of the current Cell and the key passed in the function
    else
    {
        for (int i = 0; i < table.at(hashIndex).size(); i++)
        {
            if (table.at(hashIndex).at(i).key == key)
                return table.at(hashIndex).at(i).value;
        }
    }
    // We looped through every element of the chain and found no match, thus the key was not found
    return 0;
}

/**
 * @brief Prints all existing elements of the chaining hash table to an output file
 *
 * @param filename name of the output file
 */
void ChainingHashTable::printAll(std::string filename)
{
    std::ofstream fileWriter(filename);
    for (int i = 0; i < table.size(); i++)
    {
        for (int j = 0; j < table.at(i).size(); j++)
        {
            if (table.at(i).at(j).key.length() != 0)
                fileWriter << table.at(i).at(j).key << " " << table.at(i).at(j).value << std::endl;
        }
    }
}

/**
 * @brief Overloaded subscript operator 
 * 
 * @param key string key to be found
 * @return int corresponding integer value at hash(key) index
 */
int ChainingHashTable::operator[](std::string key)
{
    return get(key);
}