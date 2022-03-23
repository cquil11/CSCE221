#include <vector>
#include <iostream>

std::vector<long long unsigned> facts;

long long unsigned fact(short unsigned n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}

long long unsigned sumFactNaive(short unsigned n1, short unsigned n2)
{
    return fact(n1) + fact(n2);
}

long long unsigned sumFact(short unsigned n1, short unsigned n2)
{
    if (facts.size() < n1 + 1)
    {
        for (int i = facts.size(); i <= n1; i++)
        {
            facts.push_back(fact(i));
        }
    }
    if (facts.size() < n2 + 1)
    {
        for (int i = facts.size(); i <= n2; i++)
        {
            facts.push_back(fact(i));
        }
    }

    return facts.at(n1) + facts.at(n2);
}

int main()
{

    std::cout << sumFact(3, 3) << std::endl;

    return 0;
}