#include <iostream>
#include "NetworkRouter.h"
#include "DoublyLinkedList.h"
#include <string>

using namespace std;

int main()
{
	NetworkRouter net;

	net.receiveRequests(std::cin);
	net.processRequests();
	net.sendRequests(std::cout);


	return 0;
}