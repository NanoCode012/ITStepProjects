#include "stdafx.h"
#include "Dictionary.h"
#include "iostream"

typedef std::basic_string<TCHAR, std::char_traits<TCHAR>> tstring;

using namespace std;

Dictionary::Dictionary()
{
}

void Dictionary::AddWord(Word word)
{
	if (size < capacity)
	{
		words[size] = word;
		sortID[size] = size;
		
		size++;
	}
}

void Dictionary::RemoveWord(int index)
{
	//Find where the word is really is
	int temp = sortID[index];

	for (int i = temp; i < size - 1; i++)
	{
		words[i] = words[i + 1];
	}

	for (int i = 0; i < size; i++)
	{
		if (sortID[index] > temp) sortID[index]--;
	}

	size--;
}

void Dictionary::ReadFromFile(const char * keyPath, const char * definitionPath)
{
	ifstream fin(keyPath);
	string input;

	int len = 100;

	TCHAR *t = new TCHAR[len];
	TCHAR *t2 = new TCHAR[len];

	Word w;

	int index = 0;
	int sz = 0;

	size = 0;
	
	if (fin) {

		while (getline(fin, input) && index < capacity)
		{
			_stprintf_s(t, len, TEXT("%hs"), input.c_str());

			w.SetTitle(t);
			AddWord(w);

			index++;
		}
		
		fin.close();
		
	}

	
	fin.open(definitionPath);


	if (fin)
	{
		for (int i = 0; i < index; i++)
		{
			if (getline(fin, input)) _stprintf_s(t, len, TEXT("%hs"), input.c_str());
			while (getline(fin, input))
			{
				if (input == "--") break;

				_tcscat_s(t, len, TEXT("\r\n"));

				_stprintf_s(t2, len, TEXT("%hs"), input.c_str());
				_tcscat_s(t, len, t2);

			}
			SetDefinition(t, i);
		}

		fin.close();
	}

	delete[] t;
	delete[] t2;

	Sort();
	
}

void Dictionary::SaveToFile(const char * keyPath, const char * definitionPath)
{
	wofstream fout(keyPath);
	tstring t;
	for (int i = 0; i < size; i++)
	{
		t = words[sortID[i]].GetTitle();
		fout << t << endl;
	}
	fout.close();

	fout.open(definitionPath);
	for (int i = 0; i < size; i++)
	{
		t = words[sortID[i]].GetDefinition();
		
		int len = t.length();
		for (int j = 0; j < len; j++)
		{
			if (t[j] == TEXT('\r'))
			{
				if (j < len - 1 && t[j + 1] == TEXT('\n'))
				{
					fout << endl;
					j++;
				}
			}
			else
			{
				fout << t[j];
			}
			
		}

		fout << endl << "--" << endl;
	}
	fout.close();
}

void Dictionary::SetTitle(const TCHAR * c, int index)
{
	words[index].SetTitle(c);
}

void Dictionary::SetDefinition(const TCHAR * c, int index)
{
	words[index].SetDefinition(c);
}

TCHAR * Dictionary::GetTitle(int index, bool isSorted)
{
	if (isSorted)
	{
		return words[sortID[index]].GetTitle();
	}
	return words[index].GetTitle();
}

TCHAR * Dictionary::GetDefinition(int index, bool isSorted)
{
	if (isSorted)
	{
		return words[sortID[index]].GetDefinition();
	}
	return words[index].GetDefinition();
}

int Dictionary::GetSize()
{
	return size;
}

int Dictionary::GetCapacity()
{
	return capacity;
}

bool Dictionary::IsFull()
{
	return (size >= capacity);
}

void Dictionary::Sort(bool onlySortLast)
{
	int temp; int swap;

	TCHAR *t1;
	TCHAR *t2;

	if (!onlySortLast)
	{
		for (int i = 0; i < size - 1; i++)
		{
			temp = i;
			for (int j = i + 1; j < size; j++)
			{
				t1 = words[sortID[temp]].GetTitle();
				t2 = words[sortID[j]].GetTitle();

				if (_tcsncmp(t1, t2, _tcsnlen(t1, sizeof(t1))) > 0)
				{
					temp = j;
				}
			}

			swap = sortID[i];
			sortID[i] = sortID[temp];
			sortID[temp] = swap;
		}
	}
	else
	{
		temp = size - 1;
		int i;

		for (i = temp - 1; i >= 0; i--)
		{
			t1 = words[sortID[temp]].GetTitle();
			t2 = words[sortID[i]].GetTitle();

			if (_tcsncmp(t1, t2, _tcsnlen(t1, sizeof(t1))) < 0)
			{
				swap = sortID[i];
				sortID[i] = sortID[temp];
				sortID[temp] = swap;

				temp = i;
			}

		}
		
	}

}

int Dictionary::Search(const TCHAR * c)
{
	searchAmountFound = 0;

	int len = _tcslen(c);
	bool foundOnce = false;

	for (int i = 0; i < size; i++)
	{
		if (_tcsncmp(words[sortID[i]].GetTitle(), c, len) == 0)
		{
			searchID[searchAmountFound++] = i;
			foundOnce = true;
		}
		else if (foundOnce) break;
	}
	return searchAmountFound;
}

int Dictionary::GetSearchID(int index)
{
	return searchID[index];
}
