#pragma once

#include <vector>
#include <iostream>

class Graph {
protected:
    std::vector< std::vector<int> > adj;

public:
    Graph(){};
    ~Graph(){};

    virtual void addVertex() = 0;
    virtual void removeVertex(int v) = 0;
    virtual void addBidirectionalEdge(int v1, int v2) = 0;
    virtual void removeBidirectionalEdge(int v1, int v2) = 0;
    virtual bool bidirectionalEdgeExists(int v1, int v2) const = 0;

    virtual std::vector<int> getConnectedVertices(int v) const = 0;

    const std::vector< std::vector<int> >& getAdj()const {return adj;}
    friend std::ostream& operator<<(std::ostream& os, const Graph* graph);

    std::vector<int> getVertices() const{
        std::vector<int> v;
        for (unsigned i = 0; i < adj.size(); i++)
            v.push_back(i);   
        return v;
    }
};

std::ostream& operator<<(std::ostream& os, const Graph* graph)
{
    os << "\n[\n";
    auto vertices = graph->getVertices();
    for (unsigned i = 0; i < vertices.size(); i++){
        os << vertices[i] << " : ";
        
        auto connectedVertices = graph->getConnectedVertices(vertices[i]);
        os << "( ";
        for (unsigned j = 0; j < connectedVertices.size(); j++)
            os << connectedVertices[j] << " ";
        os << ")\n";
    }
    os << "]";

    return os;
}
