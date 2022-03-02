#include <iostream>
#include <stdlib.h>
#include "toojpeg.h"
#include <fstream>
#include <cmath>

std::ofstream myFile;
// write a single byte compressed by TooJpeg
void myOutput(unsigned char byte)
{
    myFile << byte;
}

unsigned getMax(const unsigned *arr, unsigned n)
{
    unsigned mx = arr[0];
    for (unsigned i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void grid_to_jpg(const unsigned **grid, unsigned size, const std::string &filename)
{
    myFile = std::ofstream(filename, std::ios_base::out | std::ios_base::binary);
    const unsigned n = size * size;
    unsigned max = getMax(grid[0], size);
    for (unsigned i = 1; i < size; i++)
    {
        unsigned tmp = getMax(grid[i], size);
        if (max < tmp)
            max = tmp;
    }

    unsigned char arr_img[n];
    for (unsigned i = 0; i < size; i++)
        for (unsigned j = 0; j < size; j++)
            arr_img[i * size + j] = char((float)grid[i][j] / max * 255);

    // start JPEG compression
    // note: myOutput is the function defined in line 18, it saves the output in example.jpg
    // optional parameters:
    const bool isRGB = false;                      // true = RGB image, else false = grayscale
    const auto quality = 90;                       // compression quality: 0 = worst, 100 = best, 80 to 90 are most often used
    const bool downsample = false;                 // false = save as YCbCr444 JPEG (better quality), true = YCbCr420 (smaller file)
    const char *comment = "TooJpeg example image"; // arbitrary JPEG comment
    auto ok = TooJpeg::writeJpeg(myOutput, arr_img, size, size, isRGB, quality, downsample, comment);
}

void print(const unsigned *arr, unsigned n)
{
    for (unsigned i = 0; i < n; i++)
        std::cout << arr[i] << " ";
}

void print(const unsigned **grid, unsigned n)
{
    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < n; j++)
            std::cout << grid[i][j] << " ";
        std::cout << std::endl;
    }
}

void shuffle(unsigned *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            unsigned t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

// Retrieves maximum number of digits used on sequence arr
unsigned getMaxNDigit(const unsigned *arr, unsigned n)
{
    unsigned max = 0;
    int count;

    for (int i = 0; i < n; i++)
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

// Retrieves digit of value at specific digit index [0, nDigits-1]
unsigned getDigitAt(unsigned value, unsigned digit)
{
    for (int i = 0; i < digit; i++)
    {
        value /= 10;
    }
    return value % 10;
}

void countSort(unsigned *arr, unsigned n, unsigned range, unsigned digit)
{
    unsigned output[n];
    int i, count[range] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[getDigitAt(arr[i], digit)]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < range; i++)
        count[i] += count[i - 1];

    // Build the output array by reordering elements according to count
    for (i = n - 1; i >= 0; i--)
    {
        int index = getDigitAt(arr[i], digit);
        count[index]--;
        output[count[index]] = arr[i];
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort
void radixsort(unsigned *arr, unsigned n)
{
    // Find the maximum number of digits
    unsigned m = getMaxNDigit(arr, n);

    // Do counting sort for every digit.
    for (unsigned i = 0; i < m; i++)
        countSort(arr, n, 10, i);
}

void sortForImage1(unsigned **grid, const unsigned size)
{
    unsigned *arr = new unsigned[size * size];

    // Convert to 1D
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            arr[(size * r) + c] = grid[r][c];
        }
    }

    radixsort(arr, size * size);

    // Convert back to 2D
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            grid[r][c] = arr[(size * r) + c];
        }
    }

    delete[] arr;
}

void sortForImage2(unsigned **grid, const unsigned size)
{
    unsigned *arr = new unsigned[size * size];

    // Convert to 1D
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            arr[(size * r) + c] = grid[r][c];
        }
    }

    radixsort(arr, size * size);

    // Convert back to 2D
    for (int i = 0; i < (size * size) / 2; i++)
    {
        unsigned temp = arr[i];
        arr[i] = arr[size * size - 1 - i];
        arr[size * size - 1 - i] = temp;
    }

    // Convert back to 2D
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            grid[r][c] = arr[(size * r) + c];
        }
    }

    delete[] arr;
}

void sortForImage3(unsigned **grid, const unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        radixsort(grid[i], size);
    }
}

void sortForImage4(unsigned **grid, const unsigned size)
{
    unsigned *curCol = new unsigned[size];

    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            curCol[c] = grid[c][r];
        }

        radixsort(curCol, size);

        for (int c = 0; c < size; c++)
        {
            grid[c][r] = curCol[c];
        }
    }

    delete[] curCol;
}

void sortForImage5(unsigned **grid, const unsigned size)
{
    // TODO
}

int main()
{

    const unsigned gridX = 1000;
    const unsigned gridY = 1000;

    unsigned *arr = new unsigned[gridX * gridY];

    unsigned **grid = new unsigned *[gridX];

    for (unsigned i = 0; i < gridX * gridY; i++)
    {
        arr[i] = i;
    }

    shuffle(arr, gridX * gridY);

    for (int i = 0; i < gridX; i++)
    {
        grid[i] = new unsigned[gridY];
        for (int j = 0; j < gridY; j++)
        {
            grid[i][j] = arr[i * gridY + j];
        }
    }

    grid_to_jpg((const unsigned **)grid, gridX, "graph.jpg");

    sortForImage1(grid, gridX);
    grid_to_jpg((const unsigned **)grid, gridX, "sort1.jpg");

    shuffle(arr, gridX * gridY);

    sortForImage2(grid, gridX);
    grid_to_jpg((const unsigned **)grid, gridX, "sort2.jpg");

    shuffle(arr, gridX * gridY);

    sortForImage3(grid, gridX);
    grid_to_jpg((const unsigned **)grid, gridX, "sort3.jpg");

    shuffle(arr, gridX * gridY);

    sortForImage4(grid, gridX);
    grid_to_jpg((const unsigned **)grid, gridX, "sort4.jpg");

    return 0;
}
