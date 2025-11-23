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