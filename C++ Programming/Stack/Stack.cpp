#include "Stack.h"

Stack::Stack(char c)
{
	Push(c);
}

void Stack::Push(char c)
{
	if (head == NULL) 
	{
		head = new Node(c);
	}
	else
	{
		Node * temp = new Node(c);
		temp->Next = head;
		head = temp;
	}
}

char Stack::Pop()
{
	if (head == NULL) return '0';
	else
	{
		int c = head->Data;
		head = head->Next;
		return c;
	}
	return 0;
}

char Stack::Peek()
{
	if (head == NULL) return '0';
	return head->Data;
}

bool Stack::IsEmpty()
{
	return (head == NULL);
}

void Stack::Clear()
{
	head = NULL;
}

int Stack::GetCount()
{
	int count = 0;
	if (head != NULL)
	{
		Node *temp = head;
		while (temp->Next != NULL)
		{
			count++;
			temp = temp->Next;
		}
	}
	return count;
}
