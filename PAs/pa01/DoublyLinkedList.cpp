// TODO: Write the source functions for the DoublyLinkedList

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "DoublyLinkedList.h"
#include "Node.h"

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList &src) : head(nullptr), tail(nullptr)
{
    Node *cursor = src.head;

    while (cursor != nullptr)
    {
        Node *nodeToAdd = new Node(cursor->data);

        if (head == nullptr)
        {
            head = nodeToAdd;
            tail = nodeToAdd;
        }
        else
        {
            tail->next = nodeToAdd;
            tail = nodeToAdd;
        }
        cursor = cursor->next;
    }
}

DoublyLinkedList &DoublyLinkedList::operator=(const DoublyLinkedList &src)
{
    // Makes sure that the DoublyLinkedList is not a reference to itself
    if (this != &src)
    {
        // Clears the current DoublyLinkedList and sets its head and tail to nullptr
        this->clear();
        head, tail = nullptr;
        Node *cursor = src.head;

        // This is the same code in the copy constructor
        while (cursor != nullptr)
        {
            Node *nodeToAdd = new Node(cursor->data);

            if (head == nullptr)
            {
                head = nodeToAdd;
                tail = nodeToAdd;
            }
            else
            {
                tail->next = nodeToAdd;
                tail = nodeToAdd;
            }
            cursor = cursor->next;
        }
    }
}

DoublyLinkedList::~DoublyLinkedList() { this->clear(); }

Node *DoublyLinkedList::getFront() const
{
    return head;
}

Node *DoublyLinkedList::getBack() const
{
    return tail;
}

size_t DoublyLinkedList::getLength() const
{
    return length;
}

void DoublyLinkedList::insert(NetworkPacket data, int index)
{
    if (index < 0 || index > length)
    {
        throw std::out_of_range("Index outside of list bounds");
    }

    Node *nodeToAdd = new Node(data);

    if (head == nullptr)
    {
        head, tail = nodeToAdd;
        return;
    }

    unsigned int currentIndex = 0;
    Node *cursor = head;

    // Loops through entire list until the cursor points at the node of the target index
    while (cursor != nullptr && currentIndex != index)
    {
        cursor = cursor->next;
        currentIndex++;
    }

    // Case 1: The node is to be added at the beginning of the DoublyLinkedList.
    // Thus, the node to be added becomes the first node and points to head (the next node).
    // nodeToAdd's previous node is by default nullptr so nothing is changed in that respect.
    if (cursor == head)
    {
        nodeToAdd->next = head;
        head = nodeToAdd;
    }
    else if (cursor->prev == tail)
    {
        cursor->prev->next = nodeToAdd;
        tail = nodeToAdd;
    }
}

// Helper function that streamlines the clearing of a DoublyLinkedList, used in the destructor
void DoublyLinkedList::clear()
{
    Node *cursor = nullptr;
    while (head != nullptr)
    {
        cursor = head;
        head = head->next;
        cursor->next = nullptr;
        delete cursor;
    }
    head, tail, cursor = nullptr;
    length = 0;
}