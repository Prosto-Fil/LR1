#include "String1.h"
#include <iostream>
#include <string>

using namespace std;

String::String() : string(nullptr), length(0) {}

int String::find(String& str)
{
	int result = -1, k = 1;
	for (int i = 0; i < this->length - str.get_length() + 1; i++)
	{
		for (int j = 0; j < str.get_length(); j++) if (this->string[i + j] != str.string[j])
		{
			k = 0;
			break;
		}
		if (k != 0)
		{
			result = i;
			break;
		}
		k = 1;
	}
	return result;
}

String::String(const char* str1, const char* str2)
{
	const char* ptr1 = str1;
	const char* ptr2 = str2;
	int leng1 = 0;
	int leng2 = 0;
	while (*ptr1) 
	{
		++ptr1;
		++leng1;
	}
	while (*ptr2) 
	{
		++ptr2;
		++leng2;
	}
	this->length = leng1 + leng2 + 1;
	this->string = new char[leng1 + leng2 + 1];
	for (int i = 0; i < leng1; i++)
		this->string[i] = str1[i];
	for (int i = 0; i < leng2; i++)
		this->string[i + leng1] = str2[i];
	this->string[leng1 + leng2] = 0;
}

String::String(const char* str)
{
	const char* ptr = str;
	int leng = 0;
	while (*ptr) 
	{
		++ptr;
		++leng;
	}
	this->length = leng;
	this->string = new char[leng + 1];
	for (int i = 0; i < leng; i++)
		this->string[i] = str[i];
	this->string[leng] = 0;
}

String::String(String& str)
{
	int leng = str.get_length();
	this->length = leng;
	this->string = new char[leng + 1];
	for (int i = 0; i < leng; i++)
		this->string[i] = str.string[i];
	this->string[leng] = 0;
}

char* String::get_string()
{
	return this->string;
}

String::~String()
{
	delete[] this->string;
}

String& String::operator=(String& str)
{
	delete[] this->string;
	int leng = str.get_length();
	this->length = leng;
	this->string = new char[leng + 1];
	for (int i = 0; i < leng; i++)
		this->string[i] = str.get_string()[i];
	this->string[leng] = 0;
	return *this;
}

bool String::operator==(String& s)
{
	if (this->length == s.get_length()) 
	{
		int check = 0;
		for (int i = 0; i < s.get_length(); i++)
		{
			if (this->string[i] == s[i]) check++;
			if (check == s.get_length()) 
			{
				cout << "yes" << endl;
				return true;
			}
		}
	}
	else 
	{
		cout << "no" << endl;
		return false;
	}
}

char String::operator[](int i)
{
	return this->get_string()[i];
}

int String::get_length()
{
	return this->length;
}

void String::replace(char symbol1, char symbol2)
{
	for (int i = 0; i < this->length; i++)
	{
		if (this->string[i] == symbol1) 
			this->string[i] = symbol2;
	}
}

String& String::operator+(String& str)
{
	int leng1 = this->length;
	int leng2 = str.get_length();
	char* tmp = new char[leng1 + leng2 + 1];
	for (int i = 0; i < leng1; ++i)
	{
		if (this->string[i] != 0)
			tmp[i] = this->string[i];
	}
	for (int j = 0; j < leng2; ++j)
		tmp[j + leng1] = str[j];
	tmp[leng1 + leng2] = 0;
	static String newString(tmp);
	return newString;
}

String& String::Setter(char*& text)
{
	this->length = 0;
	while (text[length] != 0) ++length;
	this->string = text;
	text = nullptr;
	return *this;
}