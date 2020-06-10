#pragma once
#include <iostream>
#include <string>

class String
{
private:
	char* string;
	int length;
public:
	String();
	String& Setter(char*& text1);
	int find(String& str);
	String(const char* str1, const char* str2);
	String(const char* str);
	String(String& str);
	char* get_string();
	~String();
	String& operator=(String& str);
	bool operator==(String& s);
	char operator[](int i);
	int get_length();
	void replace(char symbol1, char symbol2);
	String& operator+(String& str);
};