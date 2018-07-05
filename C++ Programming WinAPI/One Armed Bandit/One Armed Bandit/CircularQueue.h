#pragma once
class CircularQueue
{
	int size;
	int capacity;
	int *arr;
public:
	CircularQueue(int capacity);
	~CircularQueue();

	void Push(int num);
	bool Shift();
	bool IsFull();

	int GetValue(int index);
};

