#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
class Date
{
public:
	void Print()const;
	Date(int year=1900, int month=1, int day=1 );
	inline bool operator==(Date& d)const
	{
		return (_year == d._year) && (_month == d._month) && (_day == d._day);
	}
	inline bool operator!=(Date& d)const
	{
		return !(*this == d);
	}
	bool operator<(Date& d);
	bool operator>(Date& d);
	Date operator+(int day)const;
	Date operator+=(int day);
	Date operator-(int day)const;
	Date operator-=(int day);
	Date& operator++();
	Date& operator--();
	Date operator++(int);
	Date operator--(int);

private:
	int _year;
	int _month;
	int _day;
};
