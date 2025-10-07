#define _CRT_SECURE_NO_WARNINGS 
#include"Date.h"
void Date:: Print()const
{
	cout << _year << "-" << _month << "-" << _day << endl;
}
bool isleapyear(int year)
{
	return(year % 4 && year % 100) || (year % 400);
}
int Getmonthday(int y, int m)
{
	int arry[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (m == 2 && isleapyear(y))
	{
		return 29;
	}
	else
	{
		return arry[m];
	}
}
Date::Date(int year , int month , int day )
{
	if (year > 0 && month > 0 && month < 13 && day>0 && day < Getmonthday(year,month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		_year = 0;
		_month = 0;
		_day =0;
		cout << "error" << endl;
	}
}
bool Date:: operator<(Date& d)
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year && _month < d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day < d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Date:: operator>(Date& d)
{
	return!(*this < d)&&!(*this==d);
}
Date Date::operator+(int day)const
{
	Date ret = *this;
	ret += (day);
	return ret;
}
Date Date::operator+=(int day)
{
	this->_day += day;
	while (this->_day > Getmonthday(this->_year, this->_month))
	{
		this->_day -= Getmonthday(this->_year, this->_month);
		this->_month++;
		if (this->_month > 12)
		{
			this->_month = 1;
			this->_year++;
		}
	}
	return *this;
}
Date Date::operator-(int day)const
{
	Date ret = *this;
	ret -= (day);
	return ret;
}
Date Date::operator-=(int day)
{
    this->_day -= day;
    while (this->_day <= 0)
    {
        this->_month--;
        if (this->_month == 0)
        {
            this->_month = 12;
            this->_year--;
        }
        this->_day += Getmonthday(this->_year, this->_month);
    }
    return *this;
}
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
Date Date::operator++(int)
{
	Date temp(*this);
	*this += 1;
	return temp;
}
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int)
{
	Date temp(*this);
	*this -= 1;
	return temp;
}

