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
    /**
     * @brief Given the index of a node, propagate it down the max
     * heap if a child has a larger value
     * 
     * @param index index of a given node to downheap
     */
    void downheap(int index)
    {

        // Keeps track of the larger child of the current node
        int largerChild = index;

        // Checks that the node is still in bounds of the heap
        if (getLeft(index) < list.size() && list[getLeft(index)] > list[index])
        {
            largerChild = getLeft(index);
        }
        if (getRight(index) < list.size() && list[getRight(index)] > list[largerChild])
        {
            largerChild = getRight(index);
        }

        // Makes sure we are not swapping an index with itself and calls
        // downheap on correct node if not
        if (largerChild != index)
        {
            T temp = list.at(index);
            list.at(index) = list.at(largerChild);
            list.at(largerChild) = temp;
            downheap(largerChild);
        }
    }
    /**
     * @brief Heapify the current structure to ensure the rules of a heap
     *  are maintained; used in conjunction with the
     *  parameterized constructor that accepts a vector
     * 
     */
    void heapify()
    {
        for (int i = list.size() - 1 / 2; i >= 0; i--)
        {
            downheap(i);
        }
    }
    /**
     * @brief Insert an element into the heap; used with upheap
     * 
     * @tparam T elem element to be inserted in the MaxHeap
     */
    void insert(T elem)
    {
        // Adds the element as the last element in the heap and then
        // performs upheap on that element to make sure it's in the right spot
        list.push_back(elem);
        upheap(list.size() - 1);
    }
    /**
     * @brief Remove max element from the heap; returns max element
     *  and uses downheap   
     * 
     * @return T the maximum (first) element in the heap
     */
    T removeMax()
    {
        T maxElement = list.at(0);
        T temp = list.at(0);
        list.at(0) = list.at(list.size() - 1);
        list.at(list.size() - 1) = temp;
        list.erase(list.begin() + list.size() - 1);
        downheap(0);

        return maxElement;
    }
};

/**
 * @brief Receives an unsorted list and returns a reverse-sorted list
 *  (largest elements first)
 * 
 * @tparam T data type of elements passed in 
 * @param v unsorted vector 
 * @return vector<T> vector sorted in MaxHeap order
 */
template <typename T>
vector<T> heapsort(vector<T> v)
{
    // Create a new instance of an array to add sorted elements
    vector<T> sorted;
    // Create a MaxHeap using the constructor (that uses heapify) from the MaxHeap class
    MaxHeap<T> h(v);

    // Copys elements from heap into the vector to be returned
    while (!h.empty())
    {
        sorted.push_back(h.removeMax());
    }
    return sorted;
}
