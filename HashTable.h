#pragma once
#include <iostream>
using namespace std;
class Node {
public:
	string content;
	Node* next;
	Node* prev;
	Node()
	{
		next = NULL;
		prev = NULL;
	}
};
class HashTable {
	int size;
	Node* hash;
	int collision = 0;
public:
	HashTable(int n);
	~HashTable();
	int folder(string a);
	Node* enter(string a);
	Node* linkpastpresent(Node* currnode, string a);
	Node* search(string a);
	void print();
	Node* operator[](int n);
};