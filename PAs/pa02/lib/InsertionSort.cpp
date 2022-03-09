#include "SortLib.h"

/**
 * Sorts an array by method of "splitting" the array into a sorted and
 * unsorted section. Each value in the unsorted section (arr[1..size-1])
 * are then compared to each element in the sorted array and inserted
 * according to precedence of value.
 * 
 * @tparam T type of data stored in array
 * @param size the size of array
 */
template <typename T>
void SortLib::InsertionSort(T arr[], int size)
{
    // Essentially says that the first element in the array is "already sorted"
    // (of course it is, relative to itself). Loops through every other element 
    // that is not already sorted
    for (int i = 1; i < size; i++)
    {
        // This is the "key," or the current element we wish to compare to 
        // elements in the sorted sub-array
        int compare = arr[i];

        // Because we want to access the iterator j outside of the scope of the 
        // for loop below, we must instantiate it here
        int j;
        // Starts at the index of the array immediately preceding the index of the
        // element of interest. As long as we are still at a valid index (not negative), 
        // and the arr[j] is NOT greater than our key, we keep searching for where the key
        // belongs (where an element in the sorted array IS greater than it)
        for (j = i - 1; j >= 0 && arr[j] > compare; j--)
        {
            // Each iteration of the loop where the key does not belong, move all elements in the
            // array up one position to make room for where our key will (eventually) be inserted
            arr[j + 1] = arr[j];
        }

        // Once we found where our key belongs, we add it to the respective position
        arr[j + 1] = compare;
    }
}

template void SortLib::InsertionSort(int *, int);
