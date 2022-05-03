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
    // Reads in filename
    string filename;
    cin >> filename;

    fstream fileReader(filename);

    // Creates graph and variables to hold data to be read in
    // (first and last lines)
    Graph graph;
    unsigned numVertices, numEdges;
    unsigned startVertex, endVertex;

    // If the fstream objet was created succesfully, read the data
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

    cout << "Shortest path from " << startVertex << " to " << endVertex << ":" << endl;
    vector<Vertex *> path;

    // Retrieves the shortest path between the start and end nodes
    path = graph.shortestPath(startVertex, endVertex);

    // Prints out the shortest path
    for (auto i : path)
    { // this is a for-each loop
        cout << i->label << " ";
    }
    // cout endline at very end
    cout << endl;
    return 0;
}
