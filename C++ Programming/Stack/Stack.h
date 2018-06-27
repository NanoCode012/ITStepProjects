#pragma once
#include <iostream>
#include "Node.h"

class Stack
{
private:
	Node *head;
public:
    Stack(char c = ' ');

    void Push(char c);
    
    char Pop();
    char Peek();

    bool IsEmpty();

    void Clear();

    int GetCount();
};