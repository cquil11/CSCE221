#include "Hash.h"
#include <iostream>
#include <string>
#include <math.h>

/**
 * @brief Implementation of the Polynomial rolling hash function
 *
 * @param s string to be hashed
 * @return unsigned int hash representation of string s
 */
unsigned int Hash::PRH24(std::string s)
{
    int m = 16777215;
    int p = 137;
    long hash = 0;

    long long pow = 1;
    int i = 0;
    // Loops through all characters in given string and applies the hash function on each
    // character, modded by the capacity
    for (std::string::iterator it = s.begin(); it != s.end(); ++it)
    {
        hash = (hash + int(*it) * pow) % m;
        pow = (pow * 137) % m;
        i++;
    }

    return hash;
}