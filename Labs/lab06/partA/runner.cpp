#include <iostream>
#include "Stack.hpp"

using namespace std;

int main()
{
    Stack<int> s;

    s.push(2);
    s.push(3);
    cout << s << endl;
    s.pop();
    cout << *s.top() << endl;

    return 0;
}