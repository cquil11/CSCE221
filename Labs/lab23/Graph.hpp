#pragma once

#include <vector>

class Graph {
private:
    std::vector< std::vector<int> > adj;

public:
    Graph(){};
    ~Graph(){};

    inline std::size_t getNVertices() const {return adj.size();}

    void addVertex(){
        for (unsigned i = 0; i < adj.size(); i++)
            adj[i].push_back(false);
        
        std::vector<int> vec(adj.size() + 1);
        for (unsigned i = 0; i < vec.size(); i++)
            vec[i] = false;
        
        adj.push_back(vec);
    }

    void addBidirectionalEdge(int v1, int v2){
        adj[v1][v2] = 1;
        adj[v2][v1] = 1;
    }
    
    std::vector<int> getConnectedVertices(int v) const {
        std::vector<int> vec;

        for (unsigned i = 0; i < adj[v].size(); i++)
            if (adj[v][i])
                vec.push_back(i);
        
        return vec;
    }
};