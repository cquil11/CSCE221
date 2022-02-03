// TODO: Write the source functions for the DoublyLinkedList

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "DoublyLinkedList.h"
#include "Node.h"
#include "NetworkPacket.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList &src) : head(nullptr), tail(nullptr), length(0)
{
    Node<T> *cursor = src.head;

    if (cursor != nullptr)
    {
        for (int i = 0; i < src.length; i++)
        {
            insert(cursor->data, i);
            cursor = cursor->next;
        }
    }
}

template <typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(const DoublyLinkedList &src)
{
    // Makes sure that the DoublyLinkedList is not a reference to itself
    if (this != &src)
    {
        // Clears the current DoublyLinkedList and sets its head and tail to nullptr
        this->clear();
        head = nullptr;
        tail = nullptr;
        Node<T> *cursor = src.head;

        // This is the same code in the copy constructor

        if (cursor != nullptr)
        {
            for (int i = 0; i < src.length; i++)
            {
                insert(cursor->data, i);
                cursor = cursor->next;
            }
        }
    }
    return *this;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() { this->clear(); }

template <typename T>
int DoublyLinkedList<T>::getLength() const
{
    return length;
}

template <typename T>
Node<T> *DoublyLinkedList<T>::getFront() const
{
    return head;
}

template <typename T>
Node<T> *DoublyLinkedList<T>::getBack() const
{
    return tail;
}

template <typename T>
void DoublyLinkedList<T>::insert(T data, int index)
{
    // If index is out of bounds, then throw an exception
    if (index < 0 || index > length)
    {
        throw std::out_of_range("Index outside of list bounds");
    }

    Node<T> *nodeToAdd = new Node<T>(data);

    // Case 0: List is empty, so nodeToAdd becomes the only node in the DoublyLinkedList
    if (head == nullptr)
    {
        head = nodeToAdd;
        tail = nodeToAdd;
        length++;
        return;
    }

    unsigned int currentIndex = 0;
    Node<T> *cursor = head;

    // Loops through entire list until the cursor points at the node of the target index
    while (cursor->next != nullptr && currentIndex != index)
    {
        cursor = cursor->next;
        currentIndex++;
    }

    // Case 1: The node is to be added at the beginning of the DoublyLinkedList.
    // Thus, the node to be added becomes the first node and points to head (the next node).
    // nodeToAdd's previous node is by default nullptr so nothing is changed in that respect.
    if (cursor == head && index == 0)
    {
        nodeToAdd->next = head;
        if (head != nullptr)
        {
            head->prev = nodeToAdd;
        }
        head = nodeToAdd;
    }
    // Case 2: The node is to be added at the end of the DoublyLinkedList.
    // Thus, the node to be added becomes the final node and becomes the tail (points to nullptr).
    else if (cursor->next == nullptr && currentIndex != index)
    {
        cursor->next = nodeToAdd;
        nodeToAdd->prev = cursor;
        tail = nodeToAdd;
    }
    // Case 3: The node is to be added at a specified index between the first and last (not inclusive).
    // The cursor will stop parsing when it reaches the specified index. Then, the cursor's previous node's next node
    // becomes the nodeToAdd and subseuqeuntly nodeToAdd's next node will be cursor (the original index where cursor
    // stopped parsing through the DoublyLinkedList).
    else
    {
        cursor->prev->next = nodeToAdd;
        nodeToAdd->prev = cursor->prev;
        cursor->prev = nodeToAdd;
        nodeToAdd->next = cursor;
    }
    // Updates length of DoublyLinkedList, regardless of where the node was actually added
    length++;
}

template <typename T>
void DoublyLinkedList<T>::remove(int index)
{
    Node<T> *cursor = head;
    int currentIndex = 0;

    if (index < 0 || index > length)
    {
        throw std::out_of_range("Index outside of list bounds");
    }

    while (cursor->next != nullptr && currentIndex != index)
    {
        cursor = cursor->next;
        currentIndex++;
    }

    // Case 0: There is only one node in the DoublyLinkedList, so remove it by setting
    // head and tail to nullptr. Decrement the length by 1.
    if (cursor == head && cursor == tail)
    {
        head = nullptr;
        tail = nullptr;
        length--;
    }
    // Case 1: The target node is the first node. In this case, simply set head equal to the next node.
    else if (cursor == head)
    {
        head = head->next;
        head->prev = nullptr;
        length--;
    }
    // Case 2: The target node is the last node. In this case, set tail to the node preceding tail. Then set the node
    // after that node to nullptr (since it is the last node in the DoublyLinkedList).
    else if (cursor->next == nullptr)
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
        cursor->next->prev = cursor->prev;
        length--;
    }

    cursor->next = nullptr;
    delete cursor;
    cursor = nullptr;
}

// Helper function that streamlines the clearing of a DoublyLinkedList, used in the destructor
template <typename T>
void DoublyLinkedList<T>::clear()
{
    Node<T> *cursor = nullptr;
    while (head != nullptr)
    {
        cursor = head;
        head = head->next;
        cursor->next = nullptr;
        delete cursor;
    }
    head = nullptr;
    tail = nullptr;
    cursor = nullptr;
    length = 0;
}

template <typename T>
std::string DoublyLinkedList<T>::toString() const
{
    Node<T> *cursor = head;

    std::stringstream ss;

    while (cursor != nullptr)
    {
        ss << cursor->data << " ";
        cursor = cursor->next;
    }
    return ss.str();
}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<NetworkPacket>;
