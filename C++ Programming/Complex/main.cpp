#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
    Complex a (50, 3);
    Complex b (3, -8);

    Complex c = a / b;
	c.Output();
	cout << endl;

	Complex d = a - b;
	d.Output();
	cout << endl;
    system("pause");
    return 0;
}