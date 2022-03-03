#include "SortLib.h"

template <typename T>
void SortLib::InsertionSort(T arr[], int size)
{
    for (int i = 1; i < n; i++)
    {
        cmp = arr[i];
        int pos = 0;

        for (int j = i - 1; j >= 0 &&  arr[j] > arr[i]; j--)
        {
            arr[j + 1] = arr[j];
            pos = j;
        }

        arr[pos] = cmp;
    }
}

template void SortLib::InsertionSort(int*, int);
