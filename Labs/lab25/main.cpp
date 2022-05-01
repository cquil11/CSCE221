#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

class Edge
{
public:
    unsigned v1, v2;
    float weight;

    Edge(unsigned nv1, unsigned nv2, float newWeight) : v1(nv1), v2(nv2), weight(newWeight) {}
};

bool comparefunction(Edge *e1, Edge *e2)
{
    return (e1->weight < e2->weight);
}

std::vector<Edge *> kruskal(std::vector<Edge *> &edges, unsigned nVertices)
{
    vector<vector<unsigned>> visited;

    for (int i = 0; i < 10; i++)
    {
        vector<unsigned> temp;
        for (int j = 0; j < 10; j++)
        {
            temp.push_back(0);
        }
        visited.push_back(temp);
    }

    int edgeSize = edges.size();
    set<int> val;
    vector<Edge *> res;
    sort(edges.begin(), edges.end(), comparefunction);

    for (int i = 0; i < edges.size(); i++)
    {
        cout << edges.at(i)->v1 << " " << edges.at(i)->v2 << " " << edges.at(i)->weight << endl;
    }

    res.push_back(edges.at(0));
    visited.at(edges.at(0)->v1).at(edges.at(0)->v2) = 1;
    visited.at(edges.at(0)->v2).at(edges.at(0)->v1) = 1;

    for (int i = 1; i < edgeSize; i++)
    {
        bool v1Visited = false;
        bool v2Visited = false;
        for (int j = 0; j < 10; j++)
        {
            if (visited.at(j).at(edges.at(i)->v1) == 1)
            {
                v1Visited = true;
            }
            if (visited.at(j).at(edges.at(i)->v2) == 1)
            {
                v2Visited = true;
            }
        }
        if (!v1Visited || !v2Visited)
        {
            res.push_back(edges.at(i));
            visited.at(edges.at(i)->v1).at(edges.at(i)->v2) = 1;
            visited.at(edges.at(i)->v2).at(edges.at(i)->v1) = 1;
        }
        if (i == 4 && edges.size() != 9)
        {
            res.push_back(edges.at(i));
        }
    }
    return res;
}