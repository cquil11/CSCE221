#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class MaxHeap
{
private:
    vector<T> list;

public:
    MaxHeap() {}
    MaxHeap(vector<T> v)
    {
        list = v;
        heapify();
    }
    int getParent(int index) const { return (index - 1) / 2; }
    int getLeft(int index) const { return index * 2 + 1; }
    int getRight(int index) const { return index * 2 + 2; }
    bool empty() const { return list.size() == 0; }
    void upheap(int index)
    {
        if (index >= 0 && getParent(index) >= 0 && (list.at(index) > list.at(getParent(index))))
        {
            // swap(list.at(index), list.at(getParent(index)));
            T temp = list.at(index);
            list.at(index) = list.at(getParent(index));
            list.at(getParent(index)) = temp;
            upheap(getParent(index));
        }
    }
    void downheap(int index)
    {

        int largerChild = index;

        if (getLeft(index) < list.size() && list[getLeft(index)] > list[index])
        {
            largerChild = getLeft(index);
        }
        if (getRight(index) < list.size() && list[getRight(index)] > list[largerChild])
        {
            largerChild = getRight(index);
        }

        // Makes sure we are not swapping an index with itself
        if (largerChild != index)
        {
            T temp = list.at(index);
            list.at(index) = list.at(largerChild);
            list.at(largerChild) = temp;
            downheap(largerChild);
        }
    }
    void heapify()
    {
        for (int i = list.size() - 1 / 2; i >= 0; i--)
        {
            downheap(i);
        }
    }
    void insert(T elem)
    {
        list.push_back(elem);
        upheap(list.size() - 1);
    }
    T removeMax()
    {
        T maxElement = list.at(0);
        // swap(list.at(0), list.at(list.size() - 1));
        T temp = list.at(0);
        list.at(0) = list.at(list.size() - 1);
        list.at(list.size() - 1) = temp;
        list.erase(list.begin() + list.size() - 1);
        downheap(0);

        return maxElement;
    }
    // FIXME (for testing purposes)
    // void print()
    // {
    //     cout << "The vector elements are : ";

    //     for (int i = 0; i < list.size(); i++)
    //         cout << list.at(i) << ' ';
    //     cout << endl;
    // }
};

template <typename T>
vector<T> heapsort(vector<T> v)
{
    vector<T> sorted;
    MaxHeap<T> h(v);

    while (!h.empty())
    {
        sorted.push_back(h.removeMax());
    }
    return sorted;
}
