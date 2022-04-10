#pragma once

#include <string>

struct Node
{
	std::string key;
	int count;
	Node *next;
	Node() : key(""), count(0), next(nullptr) {}
	Node(std::string k, int v, Node *n) : key(k), count(v), next(n) {}
};

class ChainingHashTable
{
private:
	Node *data;
	const unsigned size;

public:
	ChainingHashTable(int s) : size(s), data(new Node[s]) {}
	~ChainingHashTable()
	{
		for (int i = 0; i < size; i++)
			deleteNodes(data[i].next);
		delete[] data;
	}

	void deleteNodes(Node *head)
	{
		if (!head)
			return;

		deleteNodes(head->next);
		delete head;
	}

	unsigned int hash(std::string s)
	{
		unsigned int hash = 0;
		for (auto i = s.begin(); i != s.end(); i++)
			hash += unsigned(*i);
		return hash % size;
	}

	void insert(std::string k)
	{
		unsigned hashIndex = hash(k);
		if (data[hashIndex].count == 0)
		{
			data[hashIndex].key = k;
			data[hashIndex].count++;
		}
		else if (data[hashIndex].key == k)
		{
			data[hashIndex].count++;
		}
		else
		{
			Node *cur = data[hashIndex].next;

			if (!cur)
			{
				cur = new Node(k, 1, nullptr);
				data[hashIndex].next = cur;
			}
			else
			{
				Node *prev = nullptr;

				while (cur && cur->key != k)
				{
					prev = cur;
					cur = cur->next;
				}
				if (cur)
				{
					cur->count++;
				}
				else
				{
					cur = new Node(k, 1, nullptr);
					prev->next = cur;
				}
			}
		}
	}

	bool remove(std::string k)
	{
		unsigned hashIndex = hash(k);

		if (data[hashIndex].count == 0)
		{
			return false;
		}
		else if (data[hashIndex].key == k)
		{
			data[hashIndex].key = "";
			data[hashIndex].count = 0;

			if (data[hashIndex].next)
			{
				data[hashIndex].key = data[hashIndex].next->key;
				data[hashIndex].count = data[hashIndex].next->count;
				Node *temp = data[hashIndex].next->next;
				delete data[hashIndex].next;
				data[hashIndex].next = temp;
			}
			return true;
		}
		else
		{
			Node *prev = nullptr;
			Node *cur = data[hashIndex].next;

			while (cur)
			{
				if (cur->key == k)
				{
					if (prev)
					{
						prev->next = cur->next;
					}
					else
					{
						data[hashIndex].next = cur->next;
					}
					delete cur;

					return true;
				}
				prev = cur;
				cur = cur->next;
			}
		}
		return false;
	}

	int get(std::string k)
	{
		unsigned hashIndex = hash(k);

		if (data[hashIndex].key == k)
		{
			return data[hashIndex].count;
		}
		else
		{
			Node *cur = data[hashIndex].next;
			while (cur)
			{
				if (cur->key == k)
				{
					return cur->count;
				}
				cur = cur->next;
			}
		}
		return 0;
	}
};