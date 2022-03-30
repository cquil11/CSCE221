#include "node.hpp"

template <typename T>
const Node<T> *find(const Node<T> *node, const T *v)
{
    if (!node)
        return nullptr;

    if (node->hasData(v))
    {
        return node;
    }

    short unsigned numData = node->nAllocatedData();

    if (numData == 1)
    {
        if (*v < *(node->d1))
            find(node->n1, v);
        else
            find(node->n2, v);
    }
    else if (numData == 2)
    {
        if (*v < *(node->d1))
            find(node->n1, v);
        else if (*v > *(node->d1) && *v < *(node->d2))
            find(node->n2, v);
        else
            find(node->n3, v);
    }
    else
    {
        if (*v < *(node->d1))
            find(node->n1, v);
        else if (*v > *(node->d1) && *v < *(node->d2))
            find(node->n2, v);
        else if (*v > *(node->d2) && *v < *(node->d3))
            find(node->n3, v);
        else
            find(node->n4, v);
    }

    return nullptr;
}