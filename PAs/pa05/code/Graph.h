#ifndef GRAPH_H
#define GRAPH_H

#include "LocatorHeap.h"

#include <vector>
#include <limits>

using std::vector;

class Edge;

class Vertex
{
public:
    int label;
    vector<Edge *> edges;

    // helpers stored inside a vertex to help with path finding
    // you can use different auxilliary structures if desired
    bool visited;
    float distanceTo;
    vector<Vertex *> pathTo;
    Heap<Vertex *>::Locator locator;
    bool operator<(const Vertex &v) const
    {
        return this->distanceTo < v.distanceTo;
    }

    Vertex(int l) : label(l) {}
};

class Edge
{
public:
    Vertex *v1, *v2;
    float weight;

    Edge(Vertex *nv1, Vertex *nv2, float newWeight) : v1(nv1), v2(nv2), weight(newWeight) {}
};

class Graph
{
protected:
    // TODO: store the vertices and edges in the graph
    std::vector<Vertex *> vertices;
    std::vector<Edge *> edges;

public:
    Graph() {}

    Graph(const Graph &other)
    {
        for (int i = 0; i < other.vertices.size(); i++)
        {
            insertVertex(i);
        }

        for (int i = 0; i < other.edges.size(); i++)
        {
            insertEdge(other.edges[i]->v1->label, other.edges[i]->v2->label, other.edges[i]->weight);
        }
        // for (int i = 0; i < other.vertices.size(); i++)
        // {
        //     vector<Edge *> tempEdges;
        //     vector<Vertex *> tempPathTo;
        //     for (int j = 0; j < other.vertices[i]->edges.size(); j++)
        //     {
        //         tempEdges.push_back(other.vertices[i]->edges[j]);
        //     }
        //     for (int j = 0; j < other.vertices[i]->pathTo.size(); j++)
        //     {
        //         tempPathTo.push_back(other.vertices[i]->pathTo[j]);
        //     }

        // }
        // for (int i = 0; i < other.edges.size(); i++)
        // {
        //     edges.push_back(other.edges[i]);
        // }
    }

    Graph &operator=(const Graph &other)
    {
        if (this != &other)
        {
            for (int i = 0; i < other.vertices.size(); i++)
            {
                insertVertex(i);
            }

            for (int i = 0; i < other.edges.size(); i++)
            {
                insertEdge(other.edges[i]->v1->label, other.edges[i]->v2->label, other.edges[i]->weight);
            }
        }
        return *this;
    }

    ~Graph()
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            delete vertices[i];
        }
        for (int i = 0; i < edges.size(); i++)
        {
            delete edges[i];
        }
        vertices.clear();
        edges.clear();
    }

    // TODO: complete rule of 3

    void insertVertex(int label)
    {
        vertices.push_back(new Vertex(label));
    }

    void insertEdge(int l1, int l2, float weight)
    {
        Edge *e = new Edge(vertices[l1], vertices[l2], weight);
        edges.push_back(e);
        vertices[l1]->edges.push_back(e);
    }

    vector<Vertex *> shortestPath(int start, int end)
    {
        Vertex *endVertex = vertices[end];
        Heap<Vertex *> minHeap;

        for (int i = 0; i < vertices.size(); i++)
        {
            vertices[i]->visited = false;
            vertices[i]->pathTo.clear();
            vertices[i]->distanceTo = std::numeric_limits<float>::max();
            vertices[i]->locator = minHeap.insertElement(vertices[i]);
        }

        Vertex *cur = vertices.at(start);
        cur->distanceTo = 0;
        cur->pathTo.push_back(cur);
        minHeap.update(cur->locator);
        // FIXME
        std::cout << "START = " << cur->label << " " << cur->distanceTo << std::endl;
        std::cout << "END = " << endVertex->label << " " << endVertex->distanceTo << " " << endVertex->visited << std::endl;

        while (!endVertex->visited)
        {
            cur = minHeap.removeMin();
            std::cout << "CUR = " << cur->label << " " << cur->distanceTo << std::endl;
            for (int i = 0; i < cur->edges.size(); i++)
            {
                Vertex *opp = cur->edges[i]->v2;
                if (!opp->visited)
                {
                    if (cur->distanceTo + cur->edges[i]->weight < opp->distanceTo)
                    {
                        opp->distanceTo = cur->distanceTo + cur->edges[i]->weight;
                        minHeap.update(opp->locator);
                        opp->pathTo.clear();
                        for (int j = 0; j < cur->pathTo.size(); j++)
                        {
                            opp->pathTo.push_back(cur->pathTo[j]);
                        }
                        opp->pathTo.push_back(opp);
                    }
                }
            }
            cur->visited = true;
        }
        return endVertex->pathTo;
    }

    // FIXME: Testing purposes
    void
    print()
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            std::cout << "V" << i << ": ";
            for (int j = 0; j < vertices[i]->edges.size(); j++)
            {
                std::cout << "(" << vertices[i]->edges[j]->v1->label << ", "
                          << vertices[i]->edges[j]->v2->label << ")[" << vertices[i]->edges[j]->weight << "]   ";
            }
            std::cout << "\n";
        }
    }
};

#endif
