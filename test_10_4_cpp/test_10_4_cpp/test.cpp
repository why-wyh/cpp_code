#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
class Date
{
public:
	int Isday(int y, int m)
	{
		int days[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
		if (((y % 4 == 0 && y % 100 == 0) || (y % 400 == 0)) && (m == 2))
		{
			return 28;
		}
		else
		{
			return days[m];
		}
	}
	Date (int year = 1900, int month = 1, int day = 1)
	{
		if (year > 0 && month > 0 && month < 13 && day <= Isday(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "error" << endl;
		}
		cout << 1 << endl;
	}
	~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
		cout << "end" <<endl ;
	}
	Date(const Date& b)
	{
		_year = b._year;
		_month = b._month;
		_day = b._day;
		cout << 2 << endl;
	}
	bool operator==(Date d)
	{
		if (this->_year == d._year)
		{
			if (this->_month == d._month)
			{
				if (this->_day == d._day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	void show()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date t1(2025,10,4);
	t1.show();
	Date t2(t1);
	t2.show();
	if (t1 == t2)
		cout << "=" << endl;
	
}