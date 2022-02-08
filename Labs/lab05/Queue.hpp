#pragma once
#include <iostream>

template <typename T>
class Queue
{
private:
    T *data_;

    unsigned capacity_;
    unsigned back_;
    unsigned front_;
    unsigned size_;

    const unsigned allocationOffset_;

public:
    Queue() : data_(nullptr), size_(0), front_(0), capacity_(0), back_(0), allocationOffset_(1) {}
    ~Queue()
    {
        if (data_)
            delete[] data_;
    }

    bool empty() const;
    void enqueue(T elem);
    void dequeue();
    const T *front() const;

    template <typename T2>
    friend std::ostream &operator<<(std::ostream &os, const Queue<T2> &q);

    // Getters for testing
    const T *getData() const { return data_; }
    unsigned getCapacity() const { return capacity_; }
    unsigned getBackIndex() const { return back_; }
    unsigned getFrontIndex() const { return front_; }
    unsigned getSize() const { return size_; }
};

template <typename T2>
inline std::ostream &operator<<(std::ostream &os, const Queue<T2> &q)
{
    os << "[";
    if (!q.empty())
    {
        for (unsigned i = q.front_; i < q.back_; i++)
        {
            os << " " << q.data_[i] << ",";
        }
        os << " " << q.data_[q.back_];
    }
    os << " ]";
    return os;
}
