#pragma once

#include <vector>
#include <iostream>
// Note: you can use standard template library (STL) stack and queue to help!
#include <queue>
#include <stack>

using namespace std;

class Graph
{
private:
    std::vector<std::vector<int>> adj;

public:
    Graph(){};
    ~Graph(){};

    void addVertex()
    {
        for (unsigned i = 0; i < adj.size(); i++)
            adj[i].push_back(false);

        std::vector<int> vec(adj.size() + 1);
        for (unsigned i = 0; i < vec.size(); i++)
            vec[i] = false;

        adj.push_back(vec);
    }

    void addBidirectionalEdge(int v1, int v2)
    {
        adj[v1][v2] = 1;
        adj[v2][v1] = 1;
    }

    std::vector<int> getConnectedVertices(int v) const
    {
        std::vector<int> vec;

        for (unsigned i = 0; i < adj[v].size(); i++)
            if (adj[v][i])
                vec.push_back(i);

        return vec;
    }

    void printBFS(int start)
    {
        // TODO: breadth-first search; cout each vertex number on a line
        bool *visited = new bool[adj.size()];
        for (int i = 0; i < adj.size(); i++)
        {
            visited[i] = false;
        }

        queue<int> q;
        visited[start] = true;

        q.push(start);

        while (!q.empty())
        {
            start = q.front();
            cout << start << endl;
            q.pop();

            for (int i = 0; i < adj.at(start).size(); i++)
            {
                if (adj.at(start).at(i) && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void printDFS(int start)
    {
        // TODO: depth-first search; cout each vertex number on a line
                bool *visited = new bool[adj.size()];
        for (int i = 0; i < adj.size(); i++)
        {
            visited[i] = false;
        }

        stack<int> q;
        visited[start] = true;

        q.push(start);

        while (!q.empty())
        {
            start = q.top();
            cout << start << endl;
            q.pop();

            for (int i = 0; i < adj.at(start).size(); i++)
            {
                if (adj.at(start).at(i) && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};