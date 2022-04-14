#include "Hash.h"
#include <iostream>
#include <string>
#include <math.h>

unsigned int Hash::PRH24(std::string s)
{
    int m = 16777215;
    int p = 137;
    long hash = 0;

    long long p_pow = 1;
    int i = 0;
    for (std::string::iterator it = s.begin(); it != s.end(); ++it)
    {
        hash = (hash + int(*it) * p_pow) % m;
        p_pow = (p_pow * 137) % m;
        i++;
    }

    return hash;
}