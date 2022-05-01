#include "Graph.hpp"

#include <iostream>
#include <queue>

using namespace std;

bool is2colorable(const Graph &g, int start)
{
    // True and False are our two "colors", -1 is unassigned
    int colors[g.getNVertices()]{};
    queue<int> aux;

    // Assign a color to the start vertex and add it to the auxiliary queue.
    colors[start] = 1;
    aux.push(start);

    while (!aux.empty())
    {
        int front = aux.front();
        aux.pop();
        vector<int> neighbors = g.getConnectedVertices(front);
        for (int i = 0; i < neighbors.size(); i++)
        {
            if (colors[neighbors[i]] == colors[front])
                return false;
            if (colors[neighbors[i]] == 0)
            {
                if (colors[front] == 1)
                {
                    colors[neighbors[i]] = 2;
                    aux.push(neighbors[i]);
                }
                else
                {
                    colors[neighbors[i]] = 1;
                    aux.push(neighbors[i]);    
                }
            }
        }
    }
    return true;
}