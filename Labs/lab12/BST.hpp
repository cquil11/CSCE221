#pragma once
#include <iostream>

template <typename TKey, typename TValue>
struct Node
{
    Node() : key_(TKey()), data_(TValue()), left_(nullptr), right_(nullptr) {}
    Node(TKey key, TValue data, Node<TKey, TValue> *left, Node<TKey, TValue> *right) : key_(key), data_(data), left_(left), right_(right) {}
    TKey key_;
    TValue data_;
    Node<TKey, TValue> *left_;
    Node<TKey, TValue> *right_;
};

template <typename TKey, typename TValue>
class BST
{
private:
    Node<TKey, TValue> *root_;

    void printRecursive(const Node<TKey, TValue> *n)
    {
        if (n)
        {
            std::cout << "[" << n->key_ << " : " << n->data_ << "]";
            printRecursive(n->left_);
            printRecursive(n->right_);
        }
    }

public:
    BST() : root_(nullptr) {}

    inline const Node<TKey, TValue> *root() const { return root_; }

    void insertRecurse(Node<TKey, TValue> *node, TKey key, TValue elem)
    {
        if (node->key_ < key)
        {
            if (node->right_ == nullptr)
            {
                node->right_ = new Node<TKey, TValue>(key, elem, nullptr, nullptr);
                return;
            }
            insertRecurse(node->right_, key, elem);
        }
        else
        {
            if (node->left_ == nullptr)
            {
                node->left_ = new Node<TKey, TValue>(key, elem, nullptr, nullptr);
                return;
            }
            insertRecurse(node->left_, key, elem);
        }
        return;
    }

    void insert(TKey key, TValue elem)
    {
        if (root_ == nullptr)
        {
            root_ = new Node<TKey, TValue>(key, elem, nullptr, nullptr);
            return;
        }

        insertRecurse(root_, key, elem);
    }

    TValue *searchRecurse(Node<TKey, TValue> *node, TKey key)
    {
        if (key == node->key_)
            return &node->data_;

        if (key < node->key_)
        {
            if (node->left_ == nullptr)
            {
                return nullptr;
            }
            searchRecurse(node->left_, key);
        }
        else if (key > node->key_)
        {gi
            if (node->right_ == nullptr)
            {
                return nullptr;
            }
            searchRecurse(node->right_, key);
        }
        else
            return nullptr;
    }

    TValue *search(TKey key)
    {
        if (root_ == nullptr)
        {
            return nullptr;
        }

        return searchRecurse(root_, key);
    }

    void print()
    {
        return printRecursive(root_);
    }
};