#pragma once

#include <string>
#include <stdexcept>

struct Node
{
    std::string key;
    int count;
    Node() : key(""), count(0) {}
    Node(std::string k, int v) : key(k), count(v) {}
};

class QuadraticProbingHashTable
{
private:
    Node *data;
    const unsigned size;

public:
    QuadraticProbingHashTable(unsigned s) : size(s), data(new Node[s]) {}
    ~QuadraticProbingHashTable()
    {
        delete[] data;
    }

    unsigned int hash(std::string s)
    {
        unsigned int hash = 0;
        for (auto i = s.begin(); i != s.end(); i++)
            hash += unsigned(*i);
        return hash % size;
    }

    void insert(std::string k)
    {
        unsigned int hashIndex = hash(k);

        if (data[hashIndex].key == k)
        {
            data[hashIndex].count++;
        }
        else if (data[hashIndex].key == "")
        {
            data[hashIndex] = Node(k, 1);
        }
        else
        {
            unsigned i = 1;
            unsigned curIndex = 0;

            while (i < size)
            {
                curIndex = (hashIndex + i * i) % size;
                if (data[curIndex].key == k)
                {
                    data[curIndex].count++;
                    break;
                }
                else if (data[curIndex].key == "")
                {
                    data[curIndex] = Node(k, 1);
                    break;
                }
                i++;
            }

            if (i >= size)
                throw std::runtime_error("Error: Could not find available index.");
        }
    }

    int get(std::string k)
    {
        unsigned hashIndex = hash(k);

        if (data[hashIndex].key == k)
        {
            return data[hashIndex].count;
        }
        else
        {
            unsigned i = 1;
            unsigned curIndex = 0;
            while (i < size)
            {
                curIndex = (hashIndex + i * i) % size;
                if (data[curIndex].key == k)
                    return data[curIndex].count;
                i++;
            }
        }
        return 0;
    }

    double loadFactor()
    {
        // TODO
    }
};