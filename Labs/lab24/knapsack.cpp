#include <algorithm>
#include <iostream>
#include <vector>

typedef struct item
{
    unsigned weight;
    unsigned value;
    item() : weight(0), value(0) {}
    item(unsigned w, unsigned v) : weight(w), value(v) {}
} item;

// Exact solution with Dynamic Programming
unsigned knapsack_dp(unsigned capacity, const std::vector<item> &items)
{
    if (items.size() == 1)
    {
        if (items.at(0).weight <= capacity)
        {
            return items.at(0).value;
        }
    }

    std::vector<unsigned> dp(capacity + 1);

    for (int i = 1; i < items.size() + 1; i++)
    {
        for (int w = capacity; w >= 0; w--)
        {
            if (items.at(i - 1).weight <= w)
            {
                dp[w] = std::max(dp.at(w), dp.at(w - items.at(i - 1).weight) + items.at(i - 1).value);
            }
        }
    }
    return dp.at(capacity);
}

bool compareByBang(item a, item b)
{
    return (((double)a.value) / a.weight) > (((double)b.value) / b.weight);
}

// Approximate solution guaranteed to be at least 50% of optimal with Heuristic
unsigned knapsack_he(unsigned capacity, std::vector<item> &items)
{
    std::sort(items.begin(), items.end(), compareByBang);

    int weightRemaining = capacity;
    unsigned value = 0;
    int i = 0;
    unsigned max = items.at(0).weight;
    int maxIndex = 0;

    for (int i = 0; i < items.size(); i++)
    {
        if (max < items.at(i).weight)
        {
            max = items.at(i).weight;
            maxIndex = i;
        }

        weightRemaining -= items.at(i).weight;

        if (weightRemaining < 0)
            break;
        else
            value += items.at(i).value;
    }

    while (i < items.size())
    {
        if (max < items.at(i).weight)
        {
            max = items.at(i).weight;
            maxIndex = i;
        }
        i++;
    }
    return std::max(value, items.at(maxIndex).value);
}
