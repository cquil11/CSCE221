// TODO: Write the source functions for the DoublyLinkedList

#include <iostream>
#include <string>
#include <sstream>
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
}