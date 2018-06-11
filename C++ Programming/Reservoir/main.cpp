#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	cout << "Default set capacity of List to 5" << endl;
    List list(5);


	int opt, temp;
	Reservoir tempReservoir;
	while (true)
	{
		cout << "======" << endl;
		cout << "Options : " << endl
			<< "1. Add reservoir" << endl
			<< "2. Remove reservoir" << endl
			<< "3. Get Volume" << endl
			<< "4. Get Surface Area" << endl
			<< "5. Compare reservoir type with another" << endl
			<< "6. Output" << endl
			<< "7. Save to file" << endl
			<< "8. Quit" << endl;
		
		cout << "Opt : ";
		cin >> opt;
		if (opt == 8) break;
		switch (opt)
		{
			case 1:
				cout << "Input width of reservoir : ";
				cin >> temp;
				tempReservoir.SetWidth(temp);
				cout << "Input height of reservoir : ";
				cin >> temp;
				tempReservoir.SetHeight(temp);
				cout << "Input depth of reservoir : ";
				cin >> temp;
				tempReservoir.SetDepth(temp);
				cout << "Input type of reservoir ( 0 is Sea , 1 is Pond) : ";
				cin >> temp;
				tempReservoir.SetType(temp);
				list.Insert(tempReservoir);
				break;
			case 2:
				cout << "Input ID of reservoir to remove : ";
				cin >> temp;
				list.Remove(temp);
				break;
			case 3:
				cout << "Input ID of reservoir to get volume of : ";
				cin >> temp;
				if (1 <= temp && temp <= list.GetSize()) cout << list.GetVolume(temp) << endl;
				else cout << "Invalid ID" << endl;
				break;
			case 4:
				cout << "Input ID of reservoir to get surface area of : ";
				cin >> temp;
				if (1 <= temp && temp <= list.GetSize()) cout << list.GetSurfaceArea(temp) << endl;
				else cout << "Invalid ID" << endl;
				break;
			case 5:
				cout << "Input the first ID of the reservoir you want to compare with : ";
				cin >> opt;
				cout << "Input the second ID of the reservoir you want to compare with : ";
				cin >> temp;
				if ((1 <= opt && opt <= list.GetSize()) && (1 <= temp && temp <= list.GetSize()) && (opt != temp))
				{
					cout << "The first ID is a " << (list.GetType(opt) == 0 ? "Sea" : "Pond") << endl;
					cout << "The second ID is a " << (list.GetType(temp) == 0 ? "Sea" : "Pond") << endl;
					cout << "They are " << (list.GetType(opt) == list.GetType(temp) ? "the same" : "different") << endl;
				}
				else cout << "Invalid ID" << endl;
				break;
			case 6:
				cout << "Do you want to display info about a single reservoir or all?" << endl
					<< "1. Single" << endl
					<< "2. All" << endl;
				cout << "Input option : ";

				cin >> temp;
				if (temp == 1)
				{
					cout << "What is the reservoir's ID? No : ";
					cin >> temp;
					list.Output(temp);
				}
				else
				{
					cout << "--Reservoirs--" << endl;
					list.OutputAll();
				}
				break;
			case 7:
				cout << "Do you want to save as regular text or binary? ( 1 for text, 2 for binary) : ";
				cin >> temp;
				if (temp == 1)
				{
					list.SaveToFile();
					cout << "Saved to file Data.txt as regular text" << endl;
				}
				else if (temp == 2)
				{
					list.SaveToFile("Data.bin", false);
					cout << "Saved to file Data.bin as binary" << endl;
				}
				else
				{
					cout << "Invalid Input" << endl;
				}
				break;
			default:
				cout << "Invalid Input" << endl;
		}
	}

    return 0;
}