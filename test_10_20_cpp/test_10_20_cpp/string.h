#define _CRT_SECURE_NO_WARNINGS 
#include <string.h>
#include <iostream>
#include <assert.h>
using namespace std;
 namespace why
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str = " ")
		{
			_size = strlen(str);
			_capcity = _size;
			_str = new char[_capcity + 1];
			strcpy(_str, str);
		}
		~string()
		{
			delete[]_str;
			_str = nullptr;
			_size = _capcity = 0;
		}
		size_t size() const
		{
			return _size;
		}
		size_t capcity()const
		{
			return _capcity;
		}
		void c_string()
		{
			std::cout << _str << std::endl;
		}
		char& operator[](size_t i)const
		{
			assert(i < _size);
			return _str[i];
		}
        friend ostream& operator << (ostream& out, const string& str)
        {
        for (size_t i = 0; i < str.size(); i++)
        {
        out << str[i];
        }
        return out;
        }

	private:
		size_t _size;
		size_t _capcity;
		char* _str;
	};
	void test1()
	{
		string s1("hello");
		s1.c_string();
		cout << s1 << endl;
		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it;
			it++;
		}
		cout << endl;
	}
	void test2()
	{
		string s1;
		cout << s1 << endl;
	}
};