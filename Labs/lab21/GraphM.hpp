#pragma once

#include "Graph.hpp"
#include <vector>

class GraphM : public Graph{
public:
    GraphM(){};
    ~GraphM(){};

    void addVertex(){
        adj.resize(adj.size() + 1);
        adj[adj.size() - 1].resize(adj.size());
        for (int i = 0; i < adj.size() - 1; i++)
        {
            adj[i].resize(adj[i].size() + 1);
        }
    }

    void removeVertex(int v){
        for (int i = 0; i < adj.size(); i++)
        {
            adj[i].erase(adj[i].begin() + v);
        }
        adj.erase(adj.begin() + v);
        
    }

    void addBidirectionalEdge(int v1, int v2){
        adj.at(v1).at(v2) = 1;
        adj.at(v2).at(v1) = 1;
    }

    void removeBidirectionalEdge(int v1, int v2){
        adj.at(v1).at(v2) = 0;
        adj.at(v2).at(v1) = 0;
    }

    bool bidirectionalEdgeExists(int v1, int v2) const{
        if (adj.at(v1).at(v2) == 1 && adj.at(v2).at(v1) == 1) return true;
        return false;
    }

    
    std::vector<int> getConnectedVertices(int v) const {
        std::vector<int> vec;

        for (unsigned i = 0; i < adj[v].size(); i++)
            if (adj[v][i])
                vec.push_back(i);
        
        return vec;
    }
};