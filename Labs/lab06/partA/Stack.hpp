#pragma once
#include <iostream>

template <typename T>
class Stack
{
private:
    T *data_;
    unsigned capacity_;
    unsigned back_;

    const unsigned allocationOffset_;

public:
    Stack() : data_(nullptr), capacity_(0), back_(0), allocationOffset_(1) {}
    ~Stack()
    {
        if (data_)
            delete[] data_;
    }

    bool empty() const;
    void push(T elem);
    void pop();
    const T *top() const;

    template <typename T2>
    friend std::ostream &operator<<(std::ostream &os, const Stack<T2> &q);

    // Getters for testing
    const T *getData() const { return data_; }
    unsigned getCapacity() const { return capacity_; }
    unsigned getBackIndex() const { return back_; }
    unsigned getTopIndex() const
    {
        if (empty())
            return 0;
        return back_ - 1;
    }
};

template <typename T2>
inline std::ostream &operator<<(std::ostream &os, const Stack<T2> &q)
{
    os << "[";
    if (!q.empty())
    {
        for (unsigned i = 0; i < q.back_ - 1; i++)
        {
            os << " " << q.data_[i] << ",";
        }
        os << " " << q.data_[q.back_ - 1];
    }
    os << " ]";
    return os;
}
