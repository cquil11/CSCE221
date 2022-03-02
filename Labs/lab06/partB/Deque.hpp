#pragma once
#include <iostream>

template <typename T>
struct Node {
    Node():data_(T()), next_(nullptr), prev_(nullptr){}
    Node(T data, Node<T>* next, Node<T>* prev):data_(data), next_(next), prev_(prev){}
    T data_;
    Node<T>* next_;
    Node<T>* prev_;
};


template <typename T>
class Deque
{
private:
    Node<T>* front_;
    Node<T>* back_;

public:
    Deque(): front_(nullptr), back_(nullptr){}
    ~Deque(){
        Node<T>* tmp = front_;
        while(tmp){
            Node<T>* tmp2 = tmp;
            tmp = tmp->next_;
            delete tmp2;
        }   
    }

    bool empty() const;
    void push_back(T elem);
    void push_front(T elem);
    void pop_back();
    void pop_front();
    const Node<T>* front() const;
    const Node<T>* back() const;

    template <typename T2>
    friend std::ostream& operator<<(std::ostream& os, const Deque<T2>& q);
};

template <typename T2>
inline std::ostream& operator<<(std::ostream& os, const Deque<T2>& q) {
    os << "[";
    for(Node<T2>* tmp = q.front_; tmp; tmp = tmp->next_){
        os << " " << tmp->data_;
    }
    os << " ]";
	return os;
}
