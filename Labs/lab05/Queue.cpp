#include "Queue.hpp"
#include <cstring>

template <typename T>
inline bool Queue<T>::empty() const
{
    return size_ == 0;
}

template <typename T>
const T *Queue<T>::front() const
{
    if (this->empty())
        return nullptr;

    return &data_[front_];
}

template <typename T>
void Queue<T>::enqueue(T elem)
{
    // Needs new allocation
    if (capacity_ == size_)
    {
        T *tmp = new T[capacity_ + allocationOffset_];

        if (data_)
        {
            memcpy(tmp, data_, capacity_ * sizeof(T));
            delete[] data_;
        }
        data_ = tmp;
        capacity_ += allocationOffset_;
    }

    size_++;
    back_ = (back_ + 1) % capacity_;
    data_[back_] = elem;
}

template <typename T>
void Queue<T>::dequeue()
{
    // Return if empty
    if (this->empty())
        return;

    front_ = (front_ + 1) % capacity_;
    size_--;
}

template class Queue<int>;