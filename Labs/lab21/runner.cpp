#include <iostream>
#include <string>
#include "GraphM.hpp"
#include "GraphL.hpp"

using namespace std;


int main()
{
    // Graph* m = new GraphM();
    // m->addVertex();
    // m->addVertex();
    // m->addVertex();
    // m->addVertex();
    // cout << m << endl;
    // m->addBidirectionalEdge(1, 2);
    // cout << m << endl;

    Graph *g = new GraphL();
    g->addVertex();
    for (unsigned i = 1; i < 50; i++)
    {
        g->addVertex();

        g->addBidirectionalEdge(i, i - 1);
    }
    g->addBidirectionalEdge(0, 49);
    for (unsigned i = 15; i < 19; i++)
    {
        g->removeBidirectionalEdge(i, i - 1);

        g->removeVertex(i * 2);
    }

    return 0;
}