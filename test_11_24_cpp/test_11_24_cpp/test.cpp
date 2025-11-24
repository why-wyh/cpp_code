#define _CRT_SECURE_NO_WARNINGS 
#include<cstring>
#include<iostream>
using namespace std;
class String
{
public:
	String(const char* str="")
		:_str(nullptr)
	{
		cout << "String(const char* str="")" << endl;
		if (str == nullptr)
			return ;
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);

	}
	String(const String& s)
		:_str(nullptr)
	{
		cout << "String(String& s)" << endl;
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}
	String(String&& s)
		:_str(nullptr)
	{
		cout << "String(String&& s)" << endl;
		swap(s._str, _str);
	}
private:
	char* _str;
};
String Fun(const char*str)
{
	String temp(str);
	return temp;
}

int main()
{

	int&& b = 1;
	int c = b;
	int a = 0;
	int&& d = move(a);
	String s1("asdf");
	String s2(s1);
	String s3(Fun("we"));
	String s4(move(s1));
	return 0;
}