#include <iostream>
#include <cstdlib>

void shellsort(int *arr, unsigned size, const unsigned *gapArray, unsigned gapSize)
{
}

void combsort(int *arr, unsigned size, float k)
{
    int gap = size;

    bool swapped = true;

    while (gap != 1 || swapped)
    {
        gap /= k;
        
        if (gap < 1)
        {
            gap = 1;
        }

        swapped = false;

        for (int i = 0; i < size - gap; i++)
        {
            if (arr[i + gap] < arr[i])
            {
                int temp = arr[i + gap];
                arr[i + gap] = arr[i];
                arr[i] = temp;
                swapped = true;
            }
        }
    }
}

int main()
{

    int *arr = new int[9]{1, 2, 7, 4, 5, 12, 7, 8, 9};

    combsort(arr, 9, 1.3);
    
    for (int i = 0; i < 9; i++)
    {
        std::cout << arr[i] << " ";
    }

    delete [] arr;

    return 0;
}
