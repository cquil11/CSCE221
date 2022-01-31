// TODO: Define the DoublyLinkedList class

#ifndef DOUBLY_LINKEDLIST
#define DOUBLY_LINKEDLIST

#include <iostream>
#include <string>
#include "Node.h"

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    size_t length;

public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList &other);
    DoublyLinkedList &operator=(const DoublyLinkedList &other);
    ~DoublyLinkedList();

    size_t getLength() const;
    Node *getFront() const;
    Node *getBack() const;

    void insert(NetworkPacket data, int index);
    void remove(int index);
    void clear();
    std::string toString();
};

#endif
