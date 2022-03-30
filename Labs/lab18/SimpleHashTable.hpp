#pragma once
#include <string>
#include <stdexcept>
#include <sstream>

struct Node
{
	std::string key;
	int value;
	Node() : key(""), value(0) {}
	Node(std::string k, int v) : key(k), value(v) {}
};

class SimpleHashTable
{
private:
	Node *data;
	const unsigned size;

public:
	SimpleHashTable(int s) : size(s), data(new Node[s]) {}
	~SimpleHashTable()
	{
		if (data)
			delete[] data;
	}

	// TODO
	unsigned int hash(std::string s)
	{
		unsigned hash = 0;

		std::string::iterator it;

		for (it = s.begin(); it != s.end(); it++)
		{
			hash += int(*it);
		}

		return hash % size;
	}

	// TODO
	void insert(std::string k)
	{
		unsigned hashed = hash(k);
		if (data[hashed].key == "")
		{
			data[hashed] = Node(k, 1); 
		}
		else if (data[hashed].key == k)
		{
			data[hashed].value++;
		}
		else
		{
			throw std::runtime_error("A collision occured");
		}
	}

	// TODO
	int get(std::string k)
	{
		return data[hash(k)].value;
	}
};