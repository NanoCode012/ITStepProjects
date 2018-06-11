#include <iostream>
#include "House.h"

using namespace std;

int main()
{
	int capacity;
	cout << "Input amount of apartments in house: ";
	cin >> capacity;

	House h(capacity);
	
	cout << "Capacity of each apartment default set to 2 people" << endl;

	int opt;
	char *name = new char[100];
	int temp;
	Man tempMan;
	while (true)
	{
		cout << "Options " << endl
			<< "1. Add man" << endl
			<< "2. Remove man" << endl
			<< "3. Ouput" << endl
			<< "4. Quit" << endl;

		cout << "Input option : ";
		cin >> opt;
		if (opt == 4) break;
		switch (opt)
		{
			case 1:
				cout << "Which apartment number will the man stay in? No: ";
				cin >> opt;
				cout << "What is the person's name? Name : ";
				cin >> name;
				tempMan.SetName(name);
				cout << "How is old is that person? Age : ";
				cin >> temp;
				tempMan.SetAge(temp);
				h.Add(opt, tempMan);
				break;
			case 2:
				cout << "Which apartment number was the man staying in? No : ";
				cin >> opt;
				cout << "What is the person's ID number in the apartment? No : ";
				cin >> temp;
				h.Remove(opt, temp);
				break;
			case 3:
				cout << "Do you want to display info about a single apartment or all?" << endl
					<< "1. Single" << endl
					<< "2. All" << endl;
				cout << "Input option : ";

				cin >> opt;
				if (opt == 1)
				{
					cout << "What is the apartment's number? No : ";
					cin >> opt;
					h.Output(opt);
				}
				else
				{
					cout << "--Apartments--" << endl;
					h.OutputAll();
				}
				break;
			default:
				cout << "Option inputted is out of range" << endl;
				break;
		}
	}
    return 0;
}
