#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root->left == nullptr || root->right == nullptr)
            return root->left == root->right;
        else {
            return (root->left->val == root->right->val) && isSymmetric(root->left) && isSymmetric(root->right);
        }

    }
};
class Solution {
public:
    bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
    }
};

class person
{
public:
    person(const string& name = "asd")
        :_name(name)
    {};
    person operator =(const person& p)
    {
        this->_name = p._name;
        return *this;
    }
protected:
    string _name;
};
class student :person
{
public:
    void Print()
    {
        cout << this->_st << " ";
        cout << person::_name << endl;
    }
    student(const string& p="123", int a = 123)
        :person(p)
        , _st(a)
    {};
    student(const student& s)
        :person(s)
        , _st(s._st)
    {
    };
    student operator =(const student& st)
    {
        *this = st;
        this->_st = st._st;
        return *this;
    };
private:
    int _st;
};
int main()
{
    student s1;
    s1.Print();
    student s2(s1);
    s2.Print();
    student s3 = s2;
    s3.Print();
    
}