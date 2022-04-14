#include "ChainingHashTable.h"
#include <string>
#include <iostream>
#include <fstream>

ChainingHashTable::ChainingHashTable() : capacity(0), table(0) {}

ChainingHashTable::ChainingHashTable(unsigned capacity) : capacity(capacity), table(capacity) {}

ChainingHashTable::~ChainingHashTable() {}

unsigned int ChainingHashTable::hash(std::string key)
{
    return Hash::PRH24(key) % capacity;
}

void ChainingHashTable::insert(std::string key, int val)
{

}

int ChainingHashTable::remove(std::string key)
{

}

int ChainingHashTable::get(std::string key)
{

}

void ChainingHashTable::printAll(std::string filename)
{

}

int ChainingHashTable::operator[](std::string key)
{
    return get(key);
}