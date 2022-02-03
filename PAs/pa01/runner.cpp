#include <iostream>
#include "NetworkRouter.h"
#include "DoublyLinkedList.h"
#include <string>

using namespace std;

int main()
{
	NetworkRouter net;

	// net.receiveRequests(std::cin);
	// net.processRequests();
	// net.sendRequests(std::cout);

	DoublyLinkedList dll;
	NetworkPacket n1("0", "0", "A", "Hello!");
	NetworkPacket n2("0", "0", "B", "Howdy!");
	NetworkPacket n3("10", "5", "C", "");
	NetworkPacket n4("5", "10", "D", "TAMU");
	dll.insert(n1, 0);
	dll.insert(n2, 1);
	dll.insert(n3, 2);
	dll.insert(n4, 3);
	DoublyLinkedList dll2(dll);

	cout << "List 1: " << dll.toString() << "\n\nList 2:" << dll2.toString() << endl;

	dll2.remove(1);
	dll.remove(2);
	dll.insert(n1, 0);

	cout << "List 1: " << dll.toString() << "\n\nList 2:" << dll2.toString() << endl;


	return 0;
}