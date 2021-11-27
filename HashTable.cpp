#include "HashTable.h"
HashTable::HashTable(int n)
{
	size = n;
	hash = new Node[n];
}
HashTable::~HashTable()
{
	delete[] hash;
}
int HashTable::folder(string a)
{
	int sum = 0;
	for (int i = 0; i < a.size(); i++)
	{
		sum += a[i];
	}
	/*int temp = sum;
	sum = 0;
	for (int i = 0; temp != 0; i++)
	{
		sum += temp % 10;
		temp = temp / 10;
	}*/
	return sum;
}
Node* HashTable::enter(string a)
{
	int key = folder(a);
	int index = (key / 2 + 3 * key + 3) % size;
	if ((hash[index]).content != "\0")
	{
		collision++;
		while ((hash[index]).content != "\0")
			index = (index + 1) % size;
	}
	(hash[index]).content = a;
	return &(hash[index]);
}
Node* HashTable::linkpastpresent(Node* currnode, string a)
{
	Node* node = new Node();
	node->content = a;
	node->prev = currnode;
	currnode->next = node;
	return node;
}
Node* HashTable::search(string a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] > 64 && a[i] < 91)
		{
			a[i] = a[i] + 32;
		}
	}
	if (a == "ate")
	{
		Node* node = search("eat");
		node != NULL ? (node = node->next) : (node = NULL);
		return node;
	}
	if (a == "went")
	{
		Node* node = search("go");
		node != NULL ? (node = node->next) : (node = NULL);
		return node;
	}
	int temp;
	int key = folder(a);
	int index = (key / 2 + 3 * key + 3) % size;
	temp = index;
	if ((hash[index]).content == a)
		return &hash[index];
	else
	{
		if (hash[index].content[0] == a[0])
		{
			Node* node = &(hash[index]);
			for (; node != NULL;)
			{
				if (node->content == a)
					return node;
				node = node->next;

			}
		}
		index = (index + 1) % size;
		while ((hash[index]).content != a && (index % size) != temp)
		{
			if ((hash[index]).content == a)
				return &hash[index];
			else if (hash[index].content[0] == a[0])
			{
				Node* node = &(hash[index]);
				for (; node != NULL;)
				{
					if (node->content == a)
						return node;
					node = node->next;
				}
			}
			index = (index + 1) % size;
		}
		if ((hash[index]).content == a)
			return &hash[index];
	}
	if (a == "was")
	{
		Node* node = search("am");
		node != NULL ? (node = node->next) : (node = NULL);
		return node;
	}
	else if (a == "were")
	{
		Node* node = search("are");
		node != NULL ? (node = node->next) : (node = NULL);
		return node;
	}
	return NULL;
}
void HashTable::print()
{
	for (int i = 0; i < size; i++)
	{
		if (hash[i].next == NULL)
			cout << "i= " << i << " " << (hash[i]).content << endl;
		else
		{
			cout << "i = " << i << " ";
			Node node = hash[i];
			for (; node.next != NULL;)
			{
				cout << node.content << " -> ";
				node = *node.next;
			}
			cout << node.content;
			cout << endl;
		}
	}
	cout << "Total collisions = " << collision;
}
Node* HashTable::operator[](int n)
{
	return &hash[n];
}