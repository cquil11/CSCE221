#include <iostream>

using namespace std;

int Fun(int n)
{
    if (n == 4)
        return 2;
    else
        return 2 * Fun(n + 1);
}

double power(double base, unsigned int exponent, int &n)
{
    if (exponent == 0)
        return 1.0;
    else
    {
        if (exponent % 2 == 0)
        {
            n++;
            return power(base * base, exponent / 2, n);
        }
        else
        {
            n += 2;
            return power(base * base, exponent / 2, n) * base;
        }
    }
}

void reverse(std::string &s, unsigned index = 0)
{
    size_t size = s.size();

    if (index == size / 2)
        return;

    char temp = s[index];
    s[index] = s[size - index - 1];
    s[size - index - 1] = temp;
    reverse(s, index + 1);
}

int maxRecursive(int *arr, int size)
{
    if (size == 1) return arr[0];
    return max(arr[size - 1], maxRecursive(arr, size - 1));
}

int main()
{
    // int n = 0;
    // double x;
    // unsigned int y;
    // cin >> x >> y;

    // cout << power(x, y, n) << endl;
    // cout << n << endl;

    // std::string s = "Hello, World";
    // std::cout << s << std::endl;
    // reverse(s);
    // std::cout << s << std::endl;

    const int SIZE = 10;
    int *arr = new int[SIZE]{1, 2, 3, 4, 5, 61, 7, 8, 9, 10};

    cout << maxRecursive(arr, SIZE) << endl;

    delete [] arr;


    return 0;
}