#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include "HashTable.h"
#include "Hash.h"
#include <string>

// Linear probing hash table class
// TODO: modify the class to use public inheritance from the base class HashTable
// Note that you'll need to specify the key and value types to instantiate the template
class ProbingHashTable {
private:
    // TODO: create the table data member, should be a list of Cell objects (defined in HashTable.h)
    // You may create a pointer and use a dynamic array or vector
    // For the dynamic array, manage new and delete with the constructors and destructors
    // For the vector, be sure to set the size to capacity in the constructor so you can direct index

public: 
    // TODO: add the constructors & destructors as specified

    // TODO: include declarations to override the pure vritual functions from the base class
};

#endif