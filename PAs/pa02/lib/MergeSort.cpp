#include "SortLib.h"

/**
 * Combines two sorted subarrays into one main array.
 *
 * @tparam T the type of data stored in arr[]
 * @param leftIndex the leftmost index of current array
 * @param middleIndex the middle index of current array
 * @param rightIndex the rightmost index of current array
 */
template <typename T>
void merge(T arr[], int leftIndex, int middleIndex, int rightIndex)
{
    // variable i will keep track of current index of left sub-array
    // variable j will keep track of current index of right sub-array
    // variable k will keep track of current index of temp array
    int i, j, k;
    i = leftIndex;
    j = middleIndex + 1;
    k = leftIndex;

    // Temporary array to be filled with sorted contents. This is so we
    // can sort the orginial array while still preserving its original content
    T temp[rightIndex + 1];

    // Enter while loop if there are still elements to be parsed in both the left
    // and right sub-array
    while (i <= middleIndex && j <= rightIndex)
    {
        // Compare element at ith position in left sub-array with element at jth
        // position in right sub-array. If left element is less than or equal to right
        // element, set kth element of temp array to left element and increment iterators
        // respectively
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        // Otherwise, set kth element of temp array to right element and increment iterators
        // respectively
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    // Enter following while loops once all elements in EITHER one of the subarrays have been accounted for.
    // Since the sub-arrays are already sorted, we can simply iterate from the index where we left off
    // (from the above while loop) and add the rest of the elements to temp at index k
    while (i <= middleIndex)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= rightIndex)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // We no longer need to preserve the elements of the original array, so we simply copy the elements in
    // the temp array over to the original array. Now we have a sorted version of the original array.
    for (int m = leftIndex; m <= rightIndex; m++)
    {
        arr[m] = temp[m];
    }

    return;
}

/**
 * Recursively divides array into subarrays until they reach size = 1.
 * Calls the merge function at the end of each call in order to sort the
 * sub-arrays one by one.
 *
 * @tparam T the type of data stored in arr[]
 * @param leftIndex the leftmost index of current array
 * @param rightIndex the rightmost index of current array
 */
template <typename T>
void localMergeSort(T arr[], int leftIndex, int rightIndex)
{
    // If leftIndex == rightIndex, that means we have an array of size 1, in which
    // case, we can go back up the call stack and begin the merge process.
    if (leftIndex < rightIndex)
    {
        // On each call, divide current array in half and call another merge sort
        // on each half
        int middleIndex = (leftIndex + rightIndex) / 2;
        localMergeSort(arr, leftIndex, middleIndex);
        localMergeSort(arr, middleIndex + 1, rightIndex);
        // Once the "halving" calls are resovled, merge the elements by comparing them
        // at each "recursive level" of the call stack
        merge(arr, leftIndex, middleIndex, rightIndex);
    }
    return;
}

/**
 * SortLib's MergeSort function only has two parameters. However, traditional
 * implementations of MergeSort take in a left and right parameter to act as bounds
 * for the function calls. Furthermore, the localMergeSort function needs a helper
 * function to actually "merge" the sub-arrays, so I have created that as well.
 * All this function does is act as a "starting point" for my functions I created.
 *
 * @tparam T the type of data stored in arr[]
 * @param size the size of arr
 */
template <typename T>
void SortLib::MergeSort(T arr[], int size)
{
    localMergeSort(arr, 0, size - 1);
}

template void SortLib::MergeSort(int *, int);
