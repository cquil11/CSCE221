#include <iostream>
#include "NetworkRouter.h"

// FIXME
#include "DoublyLinkedList.h"

int main()
{
	// NetworkRouter net;

	// net.receiveRequests(std::cin);
	// net.processRequests();
	// net.sendRequests(std::cout);

	DoublyLinkedList dll;

	NetworkPacket n1("0", "0", "A", "Hello!");
	NetworkPacket n2("0", "0", "B", "Howdy!");
	NetworkPacket n3("10", "5", "C", "");
	dll.insert(n1, 0); // empty
	dll.insert(n2, 1); // back
	dll.insert(n3, 1); // now the middle index

	return 0;
}