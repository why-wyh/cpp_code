#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
template<class T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
    int a = 1, b = 2;
    ::swap<int>(a, b);
    cout << "a = " << a << ", b = " << b << endl;
    string s ("asb");
    //string::iterator it = a.begin();
    for (auto ch : s)
    {
        cout << a ;
    }
    return 0;
}