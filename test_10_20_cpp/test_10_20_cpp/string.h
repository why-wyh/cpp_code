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
		string(const char* str = "")
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
		void reserve(size_t newcapacity)
		{
			if (newcapacity > _capcity) {
				char* newstr = new char[newcapacity + 1];
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
				_capcity = newcapacity;
			}
		}
		void push_back(const char ch)
		{
			if (_capcity == _size)
			{
				size_t newcapcity = _capcity == 0 ? 2 :_capcity * 2 + 1;
				reserve(newcapcity);
			}
			size_t end = _size;
			_str[end] = ch;
			++_size;
			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (len + _size > _capcity)
			{
				reserve(len + _size + 1);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		string& operator+=(const char ch)
		{
			push_back(ch);
			return *this;
		}
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_capcity == _size)
			{
				size_t newcapcity = _capcity == 0 ? 2 : _capcity * 2 + 1;
				reserve(newcapcity);
			}
			size_t end = _size;
			while(end>=pos)
			{
				_str[end + 1] = _str[end];
				end--;
			}
			_str[pos] = ch;
			_size++;
			return *this;
	    }
		string& insert(size_t pos, const char* str)
		{
			size_t len = strlen(str);
			if (len + _size > _capcity)
			{
				reserve(len + _size + 1);
			}
			size_t end = _size;
			while (end >= pos)
			{
				_str[end + len] = _str[end];
				end--;
			}
			strncpy(_str + pos, str, len);
			return *this;
		}
		void resize(size_t n,char c='\0')
		{
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else {
				if (n > _capcity)
				{
					reserve(n + 1);
				}
				for (int i = _size; i < n ;i++)
				{
					_str[i] = c;
				}
				_size = n;
				_str[n] = '\0';
			}
		}
		string& erase(size_t pos = 0, size_t len = npos)
		{
			if (_size - pos < len)
			{
				_size = pos;
				_str[_size] = '\0';
		     }
			else
			{
				while (pos + len <=_size)
				{
					_str[pos] = _str[pos + len];
					pos++;
				}
				_size -= len;
			}
			return *this;
		}
		size_t find(char c, size_t pos = 0) const
		{
			for (int i = pos; i < _size; i++)
			{
				if (_str[i] == c)
					return i;
			}
			return npos;
		}

		size_t find(const char* s, size_t pos = 0) const
		{
			char*p=strstr(_str, s);
			if (p == nullptr)
			{
				return npos;
			}
			else
			{
				return p - _str;
			}
		}
	private:
		size_t _size;
		size_t _capcity;
		char* _str;
		static const size_t npos = -1;
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
		s1.push_back('w');
		cout << s1 << endl;
		s1.append("wyh");
		cout << s1 << endl;
		s1 += 'a';
		cout << s1 << endl;
		s1 += "sd";
		cout << s1 << endl;
		s1.insert(5, 'a');
		cout << s1 << endl;
		cout << s1 << endl;
		s1.resize(5);
		cout << s1 << endl;
		s1.resize(10, 'c');
		cout << s1 << endl;
		s1.erase(5);
		cout << s1 << endl;
		cout << s1.find("hell") << endl;
		cout << s1.find('o') << endl;
	}
	void test2()
	{
		string s1;
		cout << s1 << endl;
	}
};