#include "SortLib.h"
#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//////////////////////////////////////////////////

unsigned getMaxNDigit(const int arr[], unsigned size)
{
    unsigned max = 0;
    int count;

    for (int i = 0; i < size; i++)
    {
        count = 0;
        int num = arr[i];
        while (num >= 1)
        {
            count++;
            num /= 10;
        }
        if (count > max)
        {
            max = count;
        }
    }

    return max;
}

unsigned getDigitAt_(unsigned value, unsigned digit)
{
    for (int i = 0; i < digit; i++)
    {
        value /= 10;
    }
    return value % 10;
}

void countSort(int arr[], int size, int range, int digit)
{
    unsigned output[size];
    int i, count[range] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < size; i++)
        count[getDigitAt_(arr[i], digit)]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < range; i++)
        count[i] += count[i - 1];

    // Build the output array by reordering elements according to count
    for (i = size - 1; i >= 0; i--)
    {
        int index = getDigitAt_(arr[i], digit);
        count[index]--;
        output[count[index]] = arr[i];
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < size; i++)
        arr[i] = output[i];
}

void RadixSort(int arr[], int size)
{
    // Find the maximum number of digits
    unsigned m = getMaxNDigit(arr, size);

    // Do counting sort for every digit.
    for (unsigned i = 0; i < m; i++)
        countSort(arr, size, 10, i);
}

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

    srand(time(0));

    const unsigned SIZE = 25;
    int a[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        a[i] = rand() % 100 + 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    // InsertionSort(a, SIZE);
    // MergeSort(a, SIZE);
    RadixSort(a, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}