#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
class Date
{
	friend ostream& operator << (ostream& _cout, const Date& a);
	friend istream& operator >> (istream& _cin, Date& a);

public:
	Date(int year = 1900, int month = 0, int day = 0)
		:_year(year)
		,_month(month)
		,_day(day)
	{ }
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator << (ostream& _cout, const Date& a)
{
	_cout << a._year << "-" << a._month << "-" << a._day << endl;
	return _cout;
}
istream& operator >> (istream& _cin, Date& a)
{
	_cin >> a._year;
	_cin >> a._month;
	_cin>> a._day;
	return _cin;
}
int main()
{
	Date a(2000, 1, 1);
	Date b;
	cout << a << b << endl;
	cin >> a;
	cout << a << b << endl;
}
//求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）。
//数据范围：0<n≤2000 
//进阶： 空间复杂度O(1) ，时间复杂度O(n)
class Sum {
public:
	static void Init() {
		_sum = 0;
		_i = 1;
	}
	Sum() {
		_sum += _i;
		_i++;
	}
	static int Getsum() {
		return _sum;
	}

private:
	static int _sum;
	static int _i;
};
int Sum::_sum = 0;
int Sum::_i = 1;

class Solution {
public:
	int Sum_Solution(int n) {
		Sum::Init();
		Sum a[n];
		return Sum::Getsum();
	}
};

//在一行上输入三个整数a,b,c(1900≦a≦2200)
//a, b, c(1900≦a≦2200)，分别代表年、月、日。保证输入的日期是合法的。
//输出描述：
//输出一个整数，代表输入的日期是这一年的第几天。

int isleapyear(int y)
{
	return((y % 100 != 0 && y % 4 == 0) || y % 400 == 0);
}
int main() {
	int y, m, d, sum;
	int data[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	while (cin >> y >> m >> d)
	{
		sum = 0;
		if (m > 2 && isleapyear(y))
		{
			sum += 1;
		}//if判断跟循环不能交换
		while (--m)
		{
			sum += data[m];
		}
		
		sum += d;
		cout << sum << endl;
	}
	return 0;
}

//描述
//有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
//输入描述：
//有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
//输出描述：
//每组数据输出一行，即日期差值
//


#include <iostream>
using namespace std;

class Date {
public:
    Date(int year, int month, int day)
        : _year(year)
        , _month(month)
        , _day(day) {
    }
    // 操作符重载加const，参数加const引用
    bool operator >(const Date& d) const {
        if (_year > d._year) {
            return true;
        }
        else if (_year == d._year && _month > d._month) {
            return true;
        }
        else if (_year == d._year && _month == d._month && _day > d._day) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator !=(const Date& d) const {
        return (_year != d._year || _month != d._month || _day != d._day);
    }
    // 提供公有接口访问私有成员
    int& Year() { return _year; }
    int& Month() { return _month; }
    int& Day() { return _day; }
private:
    int _year;
    int _month;
    int _day;
};

void swap(Date& a, Date& b)
{
    Date temp = a;
    a = b;
    b = temp;
}

int getmonthday(int y, int m)
{
    int data[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
    {
        return 29;
    }
    return data[m];
}

int main() {
    int y1, m1, d1, y2, m2, d2;
    while (scanf("%4d %2d %2d %4d %2d %2d", &y1, &m1, &d1, &y2, &m2, &d2) != EOF) {
        if (y1 == y2 && m1 == m2 && d1 == d2) {
            cout << 2 << endl;
            return 0;
        }

        int count = 0;
        Date a(y1, m1, d1);
        Date b(y2, m2, d2);
        if (b > a) {
            swap(a, b);
        }
        while (b != a) {
            ++count;
            b.Day()++;
            if (b.Day() > getmonthday(b.Year(), b.Month())) {
                b.Day() = 1;
                b.Month()++;
                if (b.Month() > 12) {
                    b.Month() = 1;
                    b.Year()++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
