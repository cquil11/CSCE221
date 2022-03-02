#include <iostream>
#include "BST.hpp"

int main()
{

    BST<int, int> t;

    for (int i = 0; i < 10; i++)
    {
        t.insert(i, i);
    }

    t.print();
    std::cout << std::endl << *(t.search(1)) << std::endl;

    return 0;
}