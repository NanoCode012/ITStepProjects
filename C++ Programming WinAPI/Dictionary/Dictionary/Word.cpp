#include "stdafx.h"
#include "Word.h"

using namespace std;

Word::Word(const TCHAR* title, const TCHAR* definition)
{
	SetTitle(title);
	SetDefinition(definition);
}

void Word::operator=(const Word & other)
{
	SetTitle(other.title);
	SetDefinition(other.definition);
}

void Word::SetTitle(const TCHAR* title)
{
	_tcscpy_s(this->title, _countof(this->title), title);
}

void Word::SetDefinition(const TCHAR* definition)
{
	_tcscpy_s(this->definition, _countof(this->definition), definition);
}

TCHAR* Word::GetTitle()
{
	return title;
}

TCHAR* Word::GetDefinition()
{
	return definition;
}
