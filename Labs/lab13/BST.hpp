#pragma once
#include <iostream>
#include <vector>

template <typename TKey, typename TValue>
struct Node
{
    Node() : key_(TKey()), data_(TValue()), left_(nullptr), right_(nullptr), parent_(nullptr) {}
    Node(TKey k, TValue d, Node<TKey, TValue> *l, Node<TKey, TValue> *r, Node<TKey, TValue> *p) : key_(k), data_(d), left_(l), right_(r), parent_(p) {}
    TKey key_;
    TValue data_;
    Node<TKey, TValue> *left_;
    Node<TKey, TValue> *right_;
    Node<TKey, TValue> *parent_;
};

template <typename TKey, typename TValue>
class BST
{
private:
    Node<TKey, TValue> *root_;

    void insert(Node<TKey, TValue> *node, TKey key, TValue elem)
    {
        if (key <= node->key_)
        {
            if (!node->left_)
            {
                node->left_ = new Node<TKey, TValue>(key, elem, nullptr, nullptr, node);
                return;
            }

            return insert(node->left_, key, elem);
        }

        if (!node->right_)
        {
            node->right_ = new Node<TKey, TValue>(key, elem, nullptr, nullptr, node);
            return;
        }

        insert(node->right_, key, elem);
    }

    Node<TKey, TValue> *search(Node<TKey, TValue> *node, TKey key)
    {
        if (!node)
            return nullptr;

        if (key == node->key_)
            return node;

        if (key < node->key_)
            return search(node->left_, key);

        return search(node->right_, key);
    }

    void printRecursive(const Node<TKey, TValue> *n)
    {
        if (n)
        {
            std::cout << "[" << n->key_ << " : " << n->data_ << "]";
            printRecursive(n->left_);
            // std::cout << "[" << n->key_ << " : " << n->data_ << "]";
            printRecursive(n->right_);
            // std::cout << "[" << n->key_ << " : " << n->data_ << "]";
        }
    }

    // helper function to update the node (n) parent pointer (p) to reference a new node (t) and free n's memory
    void removeNode(Node<TKey, TValue> *n, Node<TKey, TValue> *p, Node<TKey, TValue> *t)
    {
        if (!p)
        {
            root_ = t;
        }
        else if (p->left_ == n)
        {
            p->left_ = t;
        }
        else
        {
            p->right_ = t;
        }
        delete n;
    }

public:
    BST() : root_(nullptr) {}

    inline const Node<TKey, TValue> *root() const { return root_; }

    void insert(TKey key, TValue elem)
    {
        if (!root_)
        {
            root_ = new Node<TKey, TValue>(key, elem, nullptr, nullptr, nullptr);
            return;
        }

        // Recursively call to insert at children
        insert(root_, key, elem);
    }

    Node<TKey, TValue> *search(TKey key)
    {
        return search(root_, key);
    }

    void print()
    {
        return printRecursive(root_);
    }

    void remove(TKey key)
    {
        // TODO: implement this function
        // Hint: you may find it useful to create a helper function, at least for case 3
        Node<TKey, TValue> *n = search(key);

        // Case 0
        if (!n)
            return;
        // Case 1
        else if (!(n->left_ || n->right_))
        {
            removeNode(n, n->parent_, nullptr);
        }
        // Case 2
        else if (n->left_ && !n->right_ || !n->left_ && n->right_)
        {
            if (n->left_ && !n->right_)
            {
                removeNode(n, n->parent_, n->left_);
            }
            else
            {
                removeNode(n, n->parent_, n->right_);
            }
        }
        else
        {
            Node<TKey, TValue> *temp = n;
            n = n->left_;
            while(n->right_)
            {
                n = n->right_;
            }
            temp->data_ = n->data_;
            temp->key_ = n->key_;
            if (!n->left_)
                removeNode(n, n->parent_, nullptr);
            else    
                removeNode(n, n->parent_, n->left_);

        }
    }
};