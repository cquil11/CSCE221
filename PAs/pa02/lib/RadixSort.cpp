#include "SortLib.h"

template <typename T>
unsigned getMaxNDigit(const T arr[], unsigned size)
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

unsigned getDigitAt(unsigned value, unsigned digit)
{
    for (int i = 0; i < digit; i++)
    {
        value /= 10;
    }
    return value % 10;
}

template <typename T>
void countSort(T arr[], int size, int range, int digit)
{
    unsigned output[size];
    int i, count[range] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < size; i++)
        count[getDigitAt(arr[i], digit)]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < range; i++)
        count[i] += count[i - 1];

    // Build the output array by reordering elements according to count
    for (i = size - 1; i >= 0; i--)
    {
        int index = getDigitAt(arr[i], digit);
        count[index]--;
        output[count[index]] = arr[i];
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < size; i++)
        arr[i] = output[i];
}

template <typename T>
void SortLib::RadixSort(T arr[], int size)
{
    // Find the maximum number of digits
    unsigned m = getMaxNDigit(arr, size);

    // Do counting sort for every digit.
    for (unsigned i = 0; i < m; i++)
        countSort(arr, size, 10, i);
}

template void SortLib::RadixSort(int *, int);