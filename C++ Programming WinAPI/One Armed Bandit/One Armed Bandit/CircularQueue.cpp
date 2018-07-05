#include "stdafx.h"
#include "CircularQueue.h"

CircularQueue::CircularQueue(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	
	arr = new int[capacity];
}

CircularQueue::~CircularQueue()
{
	if (arr != NULL) delete[] arr;
}

void CircularQueue::Push(int num)
{
	if (!IsFull())
	{
		arr[size++] = num;
	}
}

bool CircularQueue::Shift()
{
	if (!IsFull())
	{
		int temp = arr[0];

		for (int i = 1; i < size; i++)
		{
			arr[i - 1] = arr[i];
		}

		arr[size - 1] = temp;

		return true;
	}
	return false;
}

bool CircularQueue::IsFull()
{
	return (size >= capacity);
}

int CircularQueue::GetValue(int index)
{
	if (index >= size) return -1;

	return arr[index];
}

