#include "String1.h"
#include <iostream>

using namespace std;

istream& operator>>(istream& in, String& str)
{
	char* ch = new char[55555];
	in >> ch;
	str.Setter(ch);
	return in;
}

ostream& operator<<(ostream& out, String& str)
{
	out << str.get_string();
	return out;
}

int main()
{
	String s1("hello", ", how are you");
	String s2("visual studio");
	String s4;
	cout << s1.get_string() << endl;
	cout << s2.get_string() << endl;
	s1 = s2;
	cout << s1.get_string() << endl;
	s1 == s2;
	cout << s2 << endl;
	String s3(s2);
	cout << s3.get_string() << endl;
	cout << s3.get_length() << endl;
	s4 = s2;
	cout << s4 << endl;
	cout << s4[1] << endl;
	String s5;
	String s6("visual");
	String s7(" studio");
	s5 = s6 + s7;
	cout << "string sum" << ": " << s5 << endl;
	s5.replace('i', 'b');
	cout << s5 << endl;
	String s8;
	cin >> s8;
	cout << s8 << endl;
	cout << s2 << " " << s7 << endl;
	int counter = s2.find(s7);
	cout << counter << endl;
	String s9(s5);
	cout << s9 << endl;
	String s10("qwwerty");
	String s11("werty");
	int counter1 = s10.find(s11);
	cout << counter1 << endl;
	cout << endl;
	return 0;
}