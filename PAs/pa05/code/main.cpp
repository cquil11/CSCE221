#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

#include "Graph.h"

int main(int argc, const char *argv[])
{
    cout << "Filename of graph to load: ";
    string filename;
    cin >> filename;

    fstream fileReader(filename);

    Graph graph;
    unsigned numVertices;
    unsigned numEdges;

    unsigned startVertex;
    unsigned endVertex;

    if (fileReader.is_open())
    {
        string line;
        getline(fileReader, line);

        stringstream ss0(line);
        ss0 >> numVertices >> numEdges;

        for (int i = 0; i < numVertices; i++)
        {
            graph.insertVertex(i);
        }

        for (int i = 0; i < numEdges; i++)
        {
            getline(fileReader, line);
            stringstream ss1(line);
            int v1Label = 0;
            int v2Label = 0;
            float weight = 0;
            ss1 >> v1Label >> v2Label >> weight;

            graph.insertEdge(v1Label, v2Label, weight);
            graph.insertEdge(v2Label, v1Label, weight);
        }

        getline(fileReader, line);
        stringstream ss2(line);
        ss2 >> startVertex >> endVertex;
    }
    // TODO: next five code snippets
    // Snippet 1: read filename and open file

    // Snippet 2: get number graph size

    // Snippet 3: create graph

    // Snippet 4: read edges

    // Snippet 5: read start and end of path

    cout << "Shortest path from " << startVertex << " to " << endVertex << ":" << endl;
    graph.print();
    vector<Vertex *> path;

    // // TODO: call shortest path on your graph for the sstart and end verices and save result to path
    path = graph.shortestPath(startVertex, endVertex);

    for (auto i : path)
    { // this is a for-each loop
        cout << i->label << " ";
    }
    // cout endline at very end
    cout << endl;
    return 0;
}
