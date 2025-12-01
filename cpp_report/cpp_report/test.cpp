#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	if (a < b)
		swap(a, b);
	while (a % b)
	{
		a = b;
		b = a / b;
	}
	cout <<b<<endl;
	return 0;
}
int main()
{
	float a, b, c;
	cin >> a >> b >> c;
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				cout << "方程为恒等,解有无穷多个" << endl;
				return 0;
			}
			else
			{
				cout << "无解" << endl;
				return 0;
			}
		}
		else
		{
			cout << "X=" << -c/b << endl;
			return 0;
		}
	}
	float t = b * b - 4 * a * c;
	if (t < 0)
	{
		cout << "无解" << endl;
		return 0;
	}
	else if(t==0)
	{
		cout << "X1=X2=" << (-b) / (2 * a) << endl;
		return 0;
	}
	else
	{
		float x1 = (-b + sqrt(t)) / (2 * a);
		float x2 = (-b - sqrt(t)) / (2 * a);
		cout << "X1=" << x1 <<" " << "X2=" << x2 << endl;
		return 0;
	}
	return 0;
}
int main()
{
	cout << sizeof(int) << endl;
	cout << sizeof(char) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(double) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(short) << endl;
	cout << sizeof(bool) << endl;
	cout << sizeof(int*) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(float*) << endl;
	cout << sizeof(double*) << endl;
	cout << sizeof(long*) << endl;
	cout << sizeof(short*) << endl;
	cout << sizeof(void*) << endl;
	return 0;
}
typedef struct stu
{
	char ID[10];
	char name[20];
	int age;
	char major[20];

}stu;
int compare(const void*a,const void* b)
{
	const stu* A = (const stu*)a;
	const stu* B = (const stu*)b;
	return strcmp(A->name, B->name);
}
int main()
{
	stu s1 = { "11111111","zhangsan",20,"chemistry" };
	stu s2 = { "22222222","lisi",19,"chemistry" };
	stu s3 = { "33333333","wamgwu",20,"chemistry" };
	stu s4 = { "4444444","xiaoming",18,"chemistry" };
	stu s5 = { "55555555","dabao",20,"chemistry" };
	stu s[] = { s1,s2,s3,s4,s5 };
	qsort(s, sizeof(s) / sizeof(s[0]), sizeof(stu), compare);
	for (auto e : s)
	{
		cout << e.ID << " ";
		cout << e.name << " ";
		cout << e.age << " ";
		cout << e.major << endl;
	}

	return 0;
}
int** vmalloc(int r, int c)
{
	int** ret;
	ret = new int* [r];
	for (int i = 0; i < r; ++i)
	{
		ret[i] = new int[c];
	}
	return ret;
}
void vfree(int** arry,int r)
{
	for(int i=0;i<r;i++)
	delete[] arry[i];
	delete[]arry;
	
}
int main()
{
	int cols, rows;
	cin >> rows >> cols;
	int**arry= vmalloc(rows, cols);
	vfree(arry,rows);
	return 0;
}
int con(int* arr)
{
	int max = arr[0];
	int min = arr[0];
	for (int i=0;i<10;i++)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}
	return max - min;
}
double con(double* arr)
{
	double max = arr[0];
	double min = arr[0];
	for (int i = 0; i < 10; i++)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}
	return max - min;

}
int main()
{
	int arr1[] = { 1,2,3,4,5,5,7,8,9,12 };

	double arr2[] = { 1.2,3.4,5.5,7.8,9.12,1.2,3.4,5.6,9.0,8.3 };
	cout << con(arr1) << endl;
	cout << con(arr2) << endl;
}
vector<double> aver(const vector<vector<double>>& vv,int n,int m)
{
	vector<double>ans(n, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ans[i] += vv[i][j];
		}
		ans[i] /= m;
	}
	sort(ans.begin(), ans.end(),greater<double>());
	return ans;

}

int main()
{
	int n,m;
	cout << "请输入学生数与科目数：" << endl;
	cin >> n >> m;
	vector<vector<double>> vv(n,vector<double>(m,0));
	for (int i = 0; i < n; i++)
	{
		cout << "请输入学生成绩" << endl;
		for (int j = 0; j < m; j++)
		{
			cin >> vv[i][j];
		}
	}
	vector<double> ans = aver(vv, n, m);
	for (int i = 0; i < n; i++)
	{
	
		
			cout << ans[i] << " ";
		
	}
	return 0;
}
int function(const string s)
{
	int sz = sizeof(s),ans=0;
	for (auto e : s)
	{
		if (s == 'a')
			ans++;
	}
	return ans;
}
int main()
{
	string S;
	cout << "请输入字符串" << endl;
	cin >> S;
	int num = function(S);
	cout << num << endl;
	return 0;
}
class ellispe
{
public:
	ellispe(int a = 0, int b = 0)
		:_a(a)
		, _b(b)
	{};
	ellispe(const ellispe& e)
	{
		_a = e._a;
		_b = e._b;
	}
	double area()
	{
		return 3.14 * _a * _b;
	}
private:
	int _a;
	int _b;
};
class student
{
private:
	char* _name;
	int _age;
public:
	~student()
	{
		_name = nullptr;
		_age = 0;
	}
};
class String
{
	String(const char* s="00000")
	{
		strcpy(_s, s);
	}
	~String()
	{
		_s = nullptr;
	}
private:
	char* _s;
};
class item
{
public:
	item(int a)
	{
		a = _a;
	}
private:
	int _a;
};
int main()
{
	ellispe e1(3, 4);
	cout << e1.area() << endl;
	return 0;
}
class student
{
private:
	char* _name;
	int _age;
public:
	~student()
	{
		_name = nullptr;
		_age = 0;
	}
};


class String
{
	String(const char* s = "00000")
	{
		strcpy(_s, s);
	}
	~String()
	{
		_s = nullptr;
	}
private:
	char* _s;
};

class item
{
public:
	item(int a)
	{
		a = _a;
	}
private:
	int _a;
};
class Person
{
public:
	Person( string name = "姓名", int age = 0)
		: _name(name)
		, _age(age)
	{
		n++;
	}
	int& Get_n()
	{
		return n;
	}
private:
	string _name;
	int _age;
	static int n;
};
int Person::n = 0;

class Complex
{
public:
	Complex(int a=0,int b=0)
		:_a(a)
		,_b(b)
	{ }
	Complex sum(Complex& c)
	{
		Complex sum;
		sum._a = c._a + _a;
		sum._b = c._b + _b;
		return sum;
	}
	void Show()
	{
		cout << _a;
		cout << "+" << _b << "i" << endl;
	}
private:
	int _a;
	int _b;
};
class point
{
public:
	point(double x=0, double y=0)
		:_x(x)
		,_y(y)
	{ }
	double& x()
	{
		return _x;
	}
	double& y()
	{
		return _y;
	}
private:
	double _x;
	double _y;
};
class line
{
public:
	line(double a = 0, double b = 0, double c=0)
		:_a(a)
		,_b(b)
		,_c(c)
	{ }
	double& a()
	{
		return _a;
	}
	double& b()
	{
		return _b;
	}
	double& c()
	{
		return _c;
	}
private:
	double _a;
	double _b;
	double _c;
};
double dist(line l, point p)
{
	double n1 = fabs(l.a() * p.x() + l.b() * p.y() + l.c());
	double n2 = sqrt(l.a() * l.a() + l.b() * l.b());
	return n1 / n2;
}
int main()
{
	Person p1;
	Person p2("wyh",21);
	Person p3 = p2;
	cout << p3.Get_n() << endl;
	Complex c1(1, 1);
	Complex c2(2, 2);
	Complex c3 = c2.sum(c1);
	c1.Show();
	c2.Show();
	cout << "c1+c2" << "=";
	c3.Show();
	line l1(1, -1, 0);
	point p1(3, 4);
	cout << dist(l1, p1) << endl;
	return 0;
}
#include<iostream> 
using namespace std;
namespace why
{
	class time
	{
	public:
		time(int hour = 24, int minute = 0, int second = 0)
			: _hour(hour), _minute(minute), _second(second)
		{
		}
		time(const time& other)
			: _hour(other._hour), _minute(other._minute), _second(other._second)
		{
		}
		void print()
		{
			cout << "STANDARD " << _hour << ':' << _minute << ':' << _second << endl;
		}
		void print() const
		{
			cout << "CONST  " << _hour << ':' << _minute << ':' << _second << endl;
		}
	private:
		int _hour, _minute, _second;
	};
}
int main()
{
	why::time a(12, 57, 48);
	a.print();

	const why::time b(11, 34, 56);
	b.print();
}
class Document
{
public:
protected:
	int _name;
};
class Book :Document
{
private:
	int _PageCount;
};
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class person
{
public:
    person(const char* name = "Enter your name")
        :_name(nullptr)
    {
        _name = new char[strlen(name) + 1];
        strcpy_s(_name, strlen(name) + 1, name); // 使用更安全的strcpy_s
    }

    virtual ~person() { // 添加虚析构函数
        delete[] _name;
    }

    virtual void show()
    {
        cout << "person::" << _name << endl;
    }
    virtual void func1() {
        cout << "person::func1" << endl;
    }
    virtual void func2() {
        cout << "person::func2" << endl;
    }
protected:
    char* _name;
};

class student : public person // 改为公有继承
{
public:
    student(const char* name = "Enter your name", const char* mj = "Enter your major", const char* ID = "Enter your ID")
        :person(name)
        , _mj(mj)
        , _ID(ID)
    {
    }

    void show() override
    {
        cout << "student::" << _name << endl;
        cout << "student::" << _ID << endl;
        cout << "student::" << _mj << endl;
    }

    void func1() override {
        cout << "student::func1" << endl;
    }
    void func2() override {
        cout << "student::func2" << endl;
    }
    virtual void func3() {
        cout << "student::func3" << endl;
    }

private:
    string _mj;
    string _ID;
};

typedef void(*VFPTR) ();

 修改打印函数，避免直接调用虚函数
void PrintVTable(VFPTR vTable[])
{
    cout << "虚表地址: " << vTable << endl;
    for (int i = 0; vTable[i] != nullptr; ++i)
    {
        printf("第%d个虚函数地址: 0X%p\n", i, vTable[i]);
         注意：直接调用虚函数指针是不安全的，这里只打印地址
    }
    cout << endl;
}

int main()
{
    person p1;
    cout << "p1::Person虚表:" << endl;
    VFPTR* VTablep1 = (VFPTR*)*(void**)&p1;
    PrintVTable(VTablep1);


    person p2;
    cout << "p2::Person虚表:" << endl;
    VFPTR* VTablep2 = (VFPTR*)*(void**)&p2;
    PrintVTable(VTablep2);

    student s1;
    cout << "s1::Student虚表:" << endl;
    VFPTR* VTables1 = (VFPTR*)*(void**)&s1;
    PrintVTable(VTables1);

    student s2;
    cout << "s2::Student虚表:" << endl;
    VFPTR* VTables2 = (VFPTR*)*(void**)&s2;
    PrintVTable(VTables2);

     测试多态行为
    cout << "测试多态行为:" << endl;
    person* ptr = &s1;
    ptr->show(); // 应该调用student的show

    return 0;
}