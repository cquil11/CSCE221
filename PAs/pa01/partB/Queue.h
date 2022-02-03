// TODO: Define the Queue class
// Note: You can do everything in this file since the functions can all be very small (hint: use your list funcitons!)

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>
#include "DoublyLinkedList.h"

class Queue
{
private:
    DoublyLinkedList data;

public:
    bool empty() const
    {
        return data.getFront() == nullptr;
    }
    void push_back(NetworkPacket d)
    {
        data.insert(d, data.getLength());
    }
    NetworkPacket pop_front()
    {
        NetworkPacket temp = data.getFront()->data;
        data.remove(0);
        return temp;
    }
    std::string toString() const{
        return data.toString();
    }
};

#endif