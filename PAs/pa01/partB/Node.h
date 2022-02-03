#ifndef NODE_H
#define NODE_H

// TODO: Define the Node class
// Note: Since the functions are all small, you can put everything in this file

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node() : data(T()), next(nullptr), prev(nullptr) {}
    Node(const T &d) : data(d), next(nullptr), prev(nullptr) {}

    T getData() { return data; }

    Node<T> *getNext(){return next; }
    Node<T> *getPrev() { return prev; }
    void setData(const T &d) { data = d; }
    void setNext(Node<T> *n) { next = n; }
    void setPrev(Node<T> *p) { prev = p; }
};

#endif