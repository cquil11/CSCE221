#ifndef NODE_H
#define NODE_H
#include "NetworkPacket.h"

// TODO: Define the Node class
// Note: Since the functions are all small, you can put everything in this file

class Node
{
public:
    NetworkPacket data;
    Node *next;
    Node *prev;

    Node() : data(NetworkPacket()), next(nullptr), prev(nullptr) {}
    Node(const NetworkPacket &d) : data(d), next(nullptr), prev(nullptr) {}

    NetworkPacket getData() { return data; }

    Node *getNext(){return next; }
    Node *getPrev() { return prev; }
    void setData(const NetworkPacket &d) { data = d; }
    void setNext(Node *n) { next = n; }
    void setPrev(Node *p) { prev = p; }
};

#endif