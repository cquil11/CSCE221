#pragma once
#include <iostream>

template <typename T>
struct Node {
    Node():data_(T()), left_(nullptr), right_(nullptr){}
    Node(T data, Node<T>* left, Node<T>* right):data_(data), left_(left), right_(right){}
    T data_;
    Node<T>* left_;
    Node<T>* right_;
};

template <typename T>
void insert(Node<T>* node, T elem){
    if (elem <= node->data_){
        if (!node->left_){
            node->left_ = new Node<T>(elem, nullptr, nullptr);
            return;
        }

        return insert(node->left_, elem);
    }   

    if (!node->right_){
        node->right_ = new Node<T>(elem, nullptr, nullptr);
        return;
    }

    insert(node->right_, elem);
}

template <typename T>
void print(const Node<T>* node){
    if (node){
        std::cout << node->data_ << " ";
        print(node->left_);
        print(node->right_);
    }
}