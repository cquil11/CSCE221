#include "Queue.hpp"

// Add your implementation here

template <typename T>
bool Queue<T>::empty() const
{
    return back_ == 0;
}

template <typename T>
void Queue<T>::enqueue(T elem)
{
    if (back_ == capacity_)
    {
        T *temp = new T[capacity_ + allocationOffset_];
        for (int i = 0; i < back_; i++)
        {
            temp[i] = data_[i];
        }

        delete[] data_;
        data_ = temp;
        capacity_ += allocationOffset_;
    }

    data_[back_] = elem;
    back_++;
}

template <typename T>
void Queue<T>::dequeue()
{
    if (empty())
    {
        return;
    }

    for (int i = 0; i < back_ - 1; i++)
    {
        data_[i] = data_[i + 1];
    }
    back_--;
}

template <typename T>
const T *Queue<T>::front() const
{
    if (empty())
    {
        return NULL;
    }

    return &data_[0];
}

template class Queue<int>;