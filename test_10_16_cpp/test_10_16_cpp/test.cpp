#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
int main()
{
	string s1("why");
	string s2;
	s2 = s1;
	string s3(s2);
	/*string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it;
		it++;
	}*/
	cout << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << size(s1) << endl;
	for (int i = 0; i < size(s1); i++)
	{
		cout<<s1[i];
	}
	cout << endl;
	string::reverse_iterator it = s1.rbegin();
	while (it != s1.rend())
	{
		cout << *it;
		it++;
	}
	return 0;
}