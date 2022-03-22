// TODO: Define the Queue class
// Note: You can do everything in this file since the functions can all be very small (hint: use your list funcitons!)

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>
#include "DoublyLinkedList.h"

template <typename T>
class Queue
{
private:
    DoublyLinkedList<T> data;

public:
    bool empty() const
    {
        return data.getFront() == nullptr;
    }
    void push_back(T d)
    {
        data.insert(d, data.getLength());
    }
    T pop_front()
    {
        T temp = data.getFront()->data;
        data.remove(0);
        return temp;
    }
    std::string toString() const{
        return data.toString();
    }
};

#endif