// #include <string>
// #include <iostream>
// #include "ProbingHashTable.h"
// #include "Hash.h"

// using namespace std;

// int main()
// {
//     // ProbingHashTable h(20);
//     // // for (int i = 0; i < 15; i++)
//     // // {
//     // //     int asciiVal = rand() % 26 + 97;
//     // //     char asciiChar = asciiVal;
//     // //     h.insert(std::string(1, asciiChar), i);
//     // // }
//     // cout << Hash::PRH24("howdy!") % 20 << endl;
//     // h.insert("howdy!", 72);
//     // h.insert("h", 2);

//     // h.printAll("");

//     ProbingHashTable h(25);
//     h.insert("marginally", h.get("marginally") + 1); // no collisions
//     // introduce collision -- 2 with same hash
//     h.insert("astronaut", h.get("astronaut") + 1);

//     cout << endl;

//     return 0;
// }