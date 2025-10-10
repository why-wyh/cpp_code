//描述
//给出年分m和一年中的第n天，算出第n天是几月几号。
//输入描述：
//输入包括两个整数y(1 <= y <= 3000)，n(1 <= n <= 366)。
//输出描述：
//可能有多组测试数据，对于每组数据， 按 yyyy - mm - dd的格式将输入中对应的日期打印出来。


#include <iostream>
#include <ostream>
using namespace std;
int Getmonthday(int y, int m)
{
    int data[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
    {
        return 29;
    }
    return data[m];
}
int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        int year = a;
        int month = 1;
        while (b > Getmonthday(year, month))
        {
            b -= Getmonthday(year, month);
            month++;
        }
        int day = b;
        printf("%04d-%02d-%02d\n", year, month, day);
    }
}
// 64 位输出请用 printf("%lld")
//描述
//设计一个程序能计算一个日期加上若干天后是什么日期。
//输入描述：
//输入第一行表示样例个数m，接下来m行每行四个整数分别表示年月日和累加的天数。
//输出描述：
//输出m行，每行按yyyy - mm - dd的个数输出。
//

#include <iostream>
using namespace std;
int Getmonthday(int y, int m) {
    int data[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)) {
        return 29;
    }
    return data[m];
}
int main() {
    int year, month, day, i, n;
    cin >> n;
    while (n--) { // 注意 while 处理多个 case
        cin >> year >> month >> day >> i;
        day += i;
        while (day > Getmonthday(year, month)) {
            day -= Getmonthday(year, month);
            month++;
            if (month > 12) {
                year++;
                month = 1;
            }
        }
        printf("%04d-%02d-%02d\n", year, month, day);
    }
}
// 64 位输出请用 printf("%lld")
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year=1900, int month=1, int day=1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date()" << endl;
	}
	~Date()
	{
		cout << "~Date()" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date* p = new Date;
	delete p;
	try
	{
		Date* p1 = (Date*)operator new(sizeof(Date));
	}
	catch (...)
	{
		cout << "exception" << endl;
	}
	
	new(p1)Date;
	operator delete(p1);
	delete(p1);
	return 0;
}