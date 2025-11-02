#include <iostream>
using namespace std;
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	if (a < b)
//		swap(a, b);
//	while (a % b)
//	{
//		a = b;
//		b = a / b;
//	}
//	cout <<b<<endl;
//	return 0;
//}
/*int main()
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
}*/
/*int main()
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
}*/
//typedef struct stu
//{
//	char ID[10];
//	char name[20];
//	int age;
//	char major[20];
//
//}stu;
//int compare(const void*a,const void* b)
//{
//	const stu* A = (const stu*)a;
//	const stu* B = (const stu*)b;
//	return strcmp(A->name, B->name);
//}
//int main()
//{
//	stu s1 = { "11111111","zhangsan",20,"chemistry" };
//	stu s2 = { "22222222","lisi",19,"chemistry" };
//	stu s3 = { "33333333","wamgwu",20,"chemistry" };
//	stu s4 = { "4444444","xiaoming",18,"chemistry" };
//	stu s5 = { "55555555","dabao",20,"chemistry" };
//	stu s[] = { s1,s2,s3,s4,s5 };
//	qsort(s, sizeof(s) / sizeof(s[0]), sizeof(stu), compare);
//	for (auto e : s)
//	{
//		cout << e.ID << " ";
//		cout << e.name << " ";
//		cout << e.age << " ";
//		cout << e.major << endl;
//	}
//
//	return 0;
//}
int main()
{
	int n,k;
	cout << "请输入钱数" << endl;
	cin >> n;
	for (int i = 0; i <= n / 5; i++)
	{
		for (int j = 0; j <= n / 3; j++)
		{
			k = 100 - i - j;
			if (k % 3 == 0 && k/3 + i * 5 + j * 3 == n&&k>0)
				cout << "公鸡：" << i << "母鸡：" << j << "雏鸡：" << k << endl;
		}
	}
}