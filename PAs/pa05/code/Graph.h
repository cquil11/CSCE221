#ifndef GRAPH_H
#define GRAPH_H

#include "LocatorHeap.h"

#include <vector>
using std::vector;


class Edge;

class Vertex
{
public:
    int label;
    vector<Edge*> edges;

    // helpers stored inside a vertex to help with path finding
    // you can use different auxilliary structures if desired
    bool visited;
    float distanceTo;
    vector<Vertex*> pathTo;
    Heap<Vertex*>::Locator locator;
    bool operator < ( const Vertex &v ) const 
    { 
        // TODO for locator heap implementation
    }

    Vertex ( int l ) : label (l) { }
};

class Edge
{
public:
    Vertex *v1, *v2;
    float weight;

    Edge ( Vertex *nv1, Vertex *nv2, float newWeight ) : v1 ( nv1 ), v2 ( nv2 ), weight ( newWeight ) { }
};


class Graph
{
protected:
    // TODO: store the vertices and edges in the graph

public:
    Graph () {}

    ~Graph ()
    {
        // TODO
    }

    // TODO: complete rule of 3

    void insertVertex ( int label )
    {
        // TODO
    }

    void insertEdge ( int l1, int l2, float weight )
    {
        // TODO
    }

    vector<Vertex*> shortestPath ( int start, int end )
    {
        // TODO: Dijkstra's algorithm
    }
};

#endif
