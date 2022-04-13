#include <string>
#include <iostream>
#include "ProbingHashTable.h"
#include "Hash.h"

int main()
{
    ProbingHashTable h;
    std::cout << Hash::PRH24("howdy") << std::endl;

    return 0;
}