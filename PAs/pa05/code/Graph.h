#ifndef GRAPH_H
#define GRAPH_H

#include "LocatorHeap.h"

#include <vector>
#include <limits>

using std::vector;

class Edge;

/**
 * @brief Represents a vertex of a graph. Encapsulates all members that
 * are useful in an implementation of Dijkstra's algorithm. 
 * 
 */
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

/**
 * @brief Represents an edge of a graph. Encapsulates all members that
 * are useful in an implementation of Dijkstra's algorithm. 
 * 
 */
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
    std::vector<Vertex *> vertices;
    std::vector<Edge *> edges;

public:
    Graph() {}

    /**
     * @brief Creates a new Graph object from a deep copy of a reference of an
     * existing Graph object. Makes use of the exisitng insertVertex and insertEdge
     * functions
     * 
     * @param other Graph to be copied
     */
    Graph(const Graph &other)
    {
        // Allocate as many vertices as other has
        for (int i = 0; i < other.vertices.size(); i++)
        {
            insertVertex(i);
        }

        // The prexisting insertEdge function already allocates a new Edge given the parameters
        // of an Edge, therefore, simply insert an edge for each edge in other's list of edges
        for (int i = 0; i < other.edges.size(); i++)
        {
            insertEdge(other.edges[i]->v1->label, other.edges[i]->v2->label, other.edges[i]->weight);
        }
    }

    /**
     * @brief 
     * 
     * @param other 
     * @return Graph& deep copy of Graph other
     */
    Graph &operator=(const Graph &other)
    {
        // Code is identical to the copy constructor except for two things. One, we check to make sure this 
        // is not trying to be assigned to itself. Two, we clear this' vertices and edges so they may be
        // properly overridden by others'
        if (this != &other)
        {
            vertices.clear();
            edges.clear();

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

    /**
     * @brief Destroy the Graph object by freeing all of its memory allocated on the heap
     * 
     */
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

    /**
     * @brief Inserts a Vertex* by adding it to the Graphs vector of vertices
     * 
     * @param label integer corresponding to the to-be-added vertex
     */
    void insertVertex(int label)
    {
        vertices.push_back(new Vertex(label));
    }

    /**
     * @brief Inserts an Edge* by adding it to the Graphs vector of edges
     * 
     * @param l1 integer corresponding to the to-be-added Edge's near endpoint
     * @param l2 integer corresponding to the to-be-added Edge's far endpoint
     * @param weight float corresponding to the to-be-added Edge's weight
     */
    void insertEdge(int l1, int l2, float weight)
    {
        // Allocate new ,emory by making a new Edge* with specified paramters
        Edge *e = new Edge(vertices[l1], vertices[l2], weight);
        // Add newly created edge to Graph's list of edges
        edges.push_back(e);
        // Add newly created edge to teh corresponding Vertex object
        vertices[l1]->edges.push_back(e);
    }

    /**
     * @brief Using Djisktra's algorithm, find the shortest path between two vertices
     * 
     * @param start label of start vertex
     * @param end label of end vertex
     * @return vector<Vertex *> list of vertices corresponding to the optimal path between start and end
     */
    vector<Vertex *> shortestPath(int start, int end)
    {
        // Create a pointer to the end vertex for future reference
        Vertex *endVertex = vertices[end];
        // Create the minHeap (priority queue) that will be used to save Vertex*
        Heap<Vertex *> minHeap;

        // Sets all the vertex visited values to false, clear the pathTo, and reset the
        // distanceTo to “infinite," also makes sure to update the corresponding locator 
        // when the elements are added to the Heap
        for (int i = 0; i < vertices.size(); i++)
        {
            vertices[i]->visited = false;
            vertices[i]->pathTo.clear();
            vertices[i]->distanceTo = std::numeric_limits<float>::max();
            vertices[i]->locator = minHeap.insertElement(vertices[i]);
        }

        // Creates a pointer to the starting vertex (according to parameters of function) and
        // sets its distance to 0
        Vertex *cur = vertices.at(start);
        cur->distanceTo = 0;
        // Adds cur to it's pathTo vertex (since the vertex "passes by itself to get to itself")
        cur->pathTo.push_back(cur);
        // Makes sure to update the Vertex in the Heap
        minHeap.update(cur->locator);

        // Loop goes until the endVertex has been marked visited because at this point
        // we can ensure we will have the optimal path
        while (!endVertex->visited)
        {
            // Removes the minimum element from the Heap and sets cur to point to that Vertex
            cur = minHeap.removeMin();
            // Visits all the unvisited incident edges of cur
            for (int i = 0; i < cur->edges.size(); i++)
            {
                // Creates a Vertex pointer (opposite) that references the far endpoint of the current node
                // AKA the "opposite" side of the current edge. If this edge is unvisited, then continue
                Vertex *opp = cur->edges[i]->v2;
                if (!opp->visited)
                {
                    // If the current path yields a distance that is lower than the one already saved for cur,
                    // the distanceTo for opp is updated and its corresponding element in the Heap is also updated.
                    // This is where the Locator comes in handy because opp's counterpart in the Heap can be directly
                    // accessed and modified
                    if (cur->distanceTo + cur->edges[i]->weight < opp->distanceTo)
                    {
                        opp->distanceTo = cur->distanceTo + cur->edges[i]->weight;
                        minHeap.update(opp->locator);
                        opp->pathTo.clear();
                        // Resolves the accumulation of paths by recognizing that the shortest path will pass through
                        // the opp Vertex
                        for (int j = 0; j < cur->pathTo.size(); j++)
                        {
                            opp->pathTo.push_back(cur->pathTo[j]);
                        }
                        opp->pathTo.push_back(opp);
                    }
                }
            }
            // Sets the current Vertex's status to visited
            cur->visited = true;
        }
        // Returns the pathTo of the endVertex which of course gives the overall optimal path between
        // the specified vertices
        return endVertex->pathTo;
    }
};

#endif
