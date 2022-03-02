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

    return data_ + front_;
}

template <typename T>
void Queue<T>::enqueue(T elem)
{
    // Needs new allocation
    if (capacity_ == size_)
    {
        T *tmp = new T[capacity_ + allocationOffset_];

        if (back_ > front_)
        {
            for (int i = front_; i < capacity_; i++)
            {
                tmp[i] = data_[i];
            }
        }
        else if (capacity_ != 0)
        {
            for (int i = 0; i < capacity_; i++)
            {
                tmp[i] = data_[i];
            }
            for (int j = 0; j < back_; j++)
            {
                tmp[j + (capacity_ - front_)] = data_[j];
            }
            front_ = 0;
            back_ = size_;
        }
        delete [] data_;
        data_ = tmp;
        capacity_ += allocationOffset_;
    }

    back_ = (front_ + size_) % capacity_;
    data_[back_] = elem;
    size_++;
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