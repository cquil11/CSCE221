// TODO: Define the DoublyLinkedList class

#ifndef DOUBLY_LINKEDLIST
#define DOUBLY_LINKEDLIST

#include <iostream>
#include <string>
#include "Node.h"

template <typename T>
class DoublyLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int length;

public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList &src);
    DoublyLinkedList &operator=(const DoublyLinkedList &src);
    ~DoublyLinkedList();

    int getLength() const;
    Node<T> *getFront() const;
    Node<T> *getBack() const;

    void insert(T data, int index);
    void remove(int index);
    void clear();
    std::string toString() const;
};

#endif
