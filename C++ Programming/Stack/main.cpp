#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack s;
	s.Push('f');
	s.Push('t');
	cout << s.Pop() << endl;
	cout << s.Pop() << endl;
	system("pause");
	return 0;
}