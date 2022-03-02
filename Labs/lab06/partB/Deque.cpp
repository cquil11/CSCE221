#include "Deque.hpp"
#include <iostream>

template <typename T>
inline bool Deque<T>::empty() const
{
    if (front_ == nullptr)
        return true;
}

template <typename T>
const Node<T> *Deque<T>::front() const
{
    return front_;
}

template <typename T>
const Node<T> *Deque<T>::back() const
{
    return back_;
}

template <typename T>
void Deque<T>::push_back(T elem)
{
    if (back_)
    {
        back_->next_ = new Node<T>(elem, nullptr, back_);
        back_ = back_->next_;
    }
    else
    {
        back_ = new Node<T>(elem, nullptr, nullptr);
        front_ = back_;
    }
}

template <typename T>
void Deque<T>::push_front(T elem)
{
    if (front_)
    {
        front_->prev_ = new Node<T>(elem, front_, nullptr);
        front_ = front_->prev_;
    }
    else
    {
        front_ = new Node<T>(elem, nullptr, nullptr);
        back_ = front_;
    }
}

template <typename T>
void Deque<T>::pop_back()
{
    if (back_ == nullptr)
    {
        return;
    }

    if (back_ != front_)
    {
        back_ = back_->prev_;
        delete back_->next_;
        back_->next_ = nullptr;
    }
    else
    {
        delete back_;
        back_ = nullptr;
        front_ = nullptr;
    }
}

template <typename T>
void Deque<T>::pop_front()
{
    if (front_ == nullptr)
    {
        return;
    }

    if (front_ != back_)
    {
        front_ = front_->next_;
        delete front_->prev_;
        front_->prev_ = nullptr;
    }
    else
    {
        delete front_;
        back_ = nullptr;
        front_ = nullptr;
    }
}

template class Deque<int>;