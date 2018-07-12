#pragma once

#include <string>
#include <tchar.h>

using namespace std;

class Word
{
private:
	TCHAR title[20];
	TCHAR definition[100];
public:
	Word(const TCHAR* title = TEXT(""), const TCHAR* definition = TEXT(""));

	void operator = (const Word &other);

	void SetTitle(const TCHAR* title);
	void SetDefinition(const TCHAR* definition);

	TCHAR* GetTitle();
	TCHAR* GetDefinition();
};

