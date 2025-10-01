#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
int main()
{
    int a = 0;
    
    cin >> a;
    cout << "a=" << a << endl;
}
int main()
{
    int a = 0;
    int& b = a;
    cout << "b=" << b << endl;
    cout << "a=" << a << endl;
    cin >> a;
    cout << "b=" << b << endl;
    cout << "a=" << a << endl;
    cin >> b;
    cout << "b=" << b << endl;
    cout << "a=" << a << endl;
}
void func(int a=10, int b = 0)
{
    cout << "a=" << a<<endl;
    cout << "b=" << b<<endl;
    cout << endl;
}
void func(double a, double b)
{
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "a+b=" << a+b << endl;
    cout << endl;
}
void func(char b,int a=0)
{
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << endl;
}
void func(int a, float b)
{
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "a+b=" << a + b << endl;
    cout << endl;
}
int main()
{
    func(4);
    func();
    func(1, 2);
    func(1.2, 2.1);
    func('b');
    func(1, (float)9.2);
}

