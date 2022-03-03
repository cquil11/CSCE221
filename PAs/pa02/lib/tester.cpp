#include "SortLib.h"
#include <iostream>

//////////////////////////////////////////////////

void merge(int arr[], int leftIndex, int middleIndex, int rightIndex)
{
    int i, j, k;
    i = leftIndex;
    j = middleIndex + 1;
    k = leftIndex; // or simply, 0

    int temp[rightIndex + 1];

    while (i <= middleIndex && j <= rightIndex)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

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

    for (int m = leftIndex; m <= rightIndex; m++)
    {
        arr[m] = temp[m];
    }

    return;
}

void localMergeSort(int arr[], int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex)
    {
        int middleIndex = (leftIndex + rightIndex) / 2;
        localMergeSort(arr, leftIndex, middleIndex);
        localMergeSort(arr, middleIndex + 1, rightIndex);
        merge(arr, leftIndex, middleIndex, rightIndex);
    }
    return;
}


void MergeSort(int arr[], int size)
{
    localMergeSort(arr, 0, size - 1);
}

//////////////////////////////////////////////////

void InsertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int compare = arr[i];

        int j;
        for (j = i - 1; j >= 0 && arr[j] > compare; j--)
        {
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = compare;
    }
}

//////////////////////////////////////////////////

int main()
{

    int a[] = {6, 2, 5, 1, 3, 1, 4};

    for (int i = 0; i < 7; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    // InsertionSort(a, 7);
    MergeSort(a, 7);

    for (int i = 0; i < 7; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}