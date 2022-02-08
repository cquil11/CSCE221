#include <iostream>
#include <string>
#include "Queue.hpp"

using namespace std;

int main()
{
    Queue<int> q;

    cout << "Empty? 1: " << q.empty() << endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << "Empty? 2: " << q.empty() << endl;
    cout << q << endl;
    cout << "Front Index, Back Index: " << q.getFrontIndex() << ", " << q.getBackIndex() << endl;
    q.dequeue();
    cout << q << endl;
    cout << "Front Index, Back Index: " << q.getFrontIndex() << ", " << q.getBackIndex() << endl;
    return 0;
}
