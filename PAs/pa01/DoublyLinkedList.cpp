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
    // If index is out of bounds, then throw an exception
    if (index < 0 || index > length)
    {
        throw std::out_of_range("Index outside of list bounds");
    }

    Node *nodeToAdd = new Node(data);

    // Case 0: List is empty, so nodeToAdd becomes the only node in the DoublyLinkedList
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
        cursor = nullptr;
    }
    // Case 2: The node is to be added at the end of the DoublyLinkedList.
    // Thus, the node to be added becomes the final node and becomes the tail (points to nullptr).
    else if (cursor->prev == tail)
    {
        cursor->prev->next = nodeToAdd;
        tail = nodeToAdd;
        cursor = nullptr;
    }
    // Case 3: The node is to be added at a specified index between the first and last (not inclusive).
    // The cursor will stop parsing when it reaches the specified index. Then, the cursor's previous node's next node
    // becomes the nodeToAdd and subseuqeuntly nodeToAdd's next node will be cursor (the original index where cursor
    // stopped parsing through the DoublyLinkedList).
    else
    {
        cursor->prev->next = nodeToAdd;
        nodeToAdd->next = cursor;
        cursor = nullptr;
    }
    // Updates length of DoublyLinkedList, regardless of where the node was actually added
    length++;
}

void DoublyLinkedList::remove(int index)
{
    Node *cursor = head;
    int currentIndex = 0;

    while (cursor != nullptr && currentIndex != index)
    {
        cursor = cursor->next;
        currentIndex++;
    }

    // Case 0: There is only one node in the DoublyLinkedList, so remove it by setting
    // head and tail to nullptr. Decrement the length by 1.
    if (cursor == head && cursor == tail)
    {
        head, tail = nullptr;
        length--;
    }
    // Case 1: The target node is the first node. In this case, simply set head equal to the next node.
    else if (cursor == head)
    {
        head = head->next;
        length--;
    }
    // Case 2: The target node is the last node. In this case, set tail to the node preceding tail. Then set the node
    // after that node to nullptr (since it is the last node in the DoublyLinkedList).
    else if (cursor->prev == tail)
    {
        tail = tail->prev;
        tail->next = nullptr;
        length--;
    }
    // Case 3: The target node is somewhere between the beginning and end of the DoublyLinkedList (not iclusive). 
    // In this case, set the cursor's previous's next to the cursor's next (essentially skipping the cursor node).
    else
    {
        cursor->prev->next = cursor->next;
        length--;
    }

    cursor->next = nullptr;
    delete cursor;
    cursor = nullptr;

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