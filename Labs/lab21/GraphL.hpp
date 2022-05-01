#pragma once

#include "Graph.hpp"
#include <vector>
#include <algorithm>

class GraphL : public Graph
{
public:
    GraphL(){};
    ~GraphL(){};

    void addVertex()
    {
        std::vector<int> n;
        adj.push_back(n);
    }

    void removeVertex(int v)
    {
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                if (adj[i][j] == v)
                {
                    adj[i].erase(adj[i].begin() + j);
                }
            }
        }
        adj.erase(adj.begin() + v);

        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                if (adj[i].at(j) > v)
                {
                    adj[i][j] = adj[i][j] - 1;
                }
            }
        }
    }

    void addBidirectionalEdge(int v1, int v2)
    {
        adj.at(v1).push_back(v2);
        adj.at(v2).push_back(v1);
    }

    void removeBidirectionalEdge(int v1, int v2)
    {
        for (int i = 0; i < adj.at(v1).size(); i++)
        {
            if (adj.at(v1).at(i) == v2)
            {
                adj.at(v1).erase(adj.at(v1).begin() + i);
            }
            break;
        }
        for (int i = 0; i < adj.at(v2).size(); i++)
        {
            if (adj.at(v2).at(i) == v1)
            {
                adj.at(v2).erase(adj.at(v2).begin() + i);
            }
            break;
        }
    }

    bool bidirectionalEdgeExists(int v1, int v2) const
    {
        if (std::find(adj.at(v1).begin(), adj.at(v1).end(), v2) != adj.at(v1).end() && std::find(adj.at(v2).begin(), adj.at(v2).end(), v1) != adj.at(v2).end())
        {
            return true;
        }
        return false;
    }

    std::vector<int> getConnectedVertices(int v) const
    {
        std::vector<int> vec;
        for (auto it = adj[v].begin(); it != adj[v].end(); it++)
            vec.push_back(*it);
        return vec;
    }
};