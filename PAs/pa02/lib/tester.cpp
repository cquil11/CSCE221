#include "SortLib.h"
#include <iostream>

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

int main()
{

    int a[] = {6, 2, 5, 1, 3, 1, 4};

    for (int i = 0; i < 7; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    InsertionSort(a, 7);

    for (int i = 0; i < 7; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}