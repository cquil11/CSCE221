#include "Stack.hpp"
#include <cstring>

template <typename T>
inline bool Stack<T>::empty() const{
    return !back_;
}

template <typename T>
const T* Stack<T>::top() const{
    if (this->empty())
        return nullptr;
    
    return &(data_[getTopIndex()]);
}

template <typename T>
void Stack<T>::push(T elem){
    // Needs new allocation
    if (capacity_ == back_){
        T* tmp = new T[capacity_ + allocationOffset_];
        
        if (data_){
            memcpy(tmp, data_, capacity_ * sizeof(T));
            delete[] data_;
        }
        data_ = tmp;
        capacity_ += allocationOffset_;
    }

    data_[back_++] = elem;
}

template <typename T>
void Stack<T>::pop(){
    // Return if empty
    if (this->empty())
        return;
    
    back_--;
}

template class Stack<int>;