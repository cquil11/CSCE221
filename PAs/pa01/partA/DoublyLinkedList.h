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
    int length;

public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList &src);
    DoublyLinkedList &operator=(const DoublyLinkedList &src);
    ~DoublyLinkedList();

    int getLength() const;
    Node *getFront() const;
    Node *getBack() const;

    void insert(NetworkPacket data, int index);
    void remove(int index);
    void clear();
    std::string toString() const;
};

#endif
