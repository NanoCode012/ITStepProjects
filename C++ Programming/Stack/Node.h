#pragma once

class Node
{
public:
	char Data;
	Node *Next;

	Node(char data);

	Node(const Node &other);
	void operator = (const Node &other);
	~Node();
};