#include "Node.h"

Node::Node(char data)
{
	this->Data = data;
}

Node::Node(const Node & other)
{
	this->Data = other.Data;
	this->Next = other.Next;
}

void Node::operator=(const Node & other)
{
	this->Data = other.Data;
	this->Next = other.Next;
}

Node::~Node()
{
	delete[] Next;
}
