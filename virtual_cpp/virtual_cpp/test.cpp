#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
class person
{
public:
	virtual void test()=0 { cout << "person::" << endl; }
	virtual ~person()=0 { cout << "~peson" << endl; }
protected:
	int a;
};
class student final :public person 
{
public:
	  void test()override { cout << "student::" << endl; }
	 ~student() { cout << "~student" << endl; }
protected:
	char c;
};

void test( person* p)
{
	p->test();
}
int main()
{
	student p1;
	//person p2;
	 test(&p1);
	 //test(&p2);
}
// 计划（详细伪代码）：
// 1. 创建一个辅助函数 isMirror(p, q)
//    - 如果 p 和 q 都为空，返回 true。
//    - 如果只有一个为空，返回 false。
//    - 如果 p->val != q->val，返回 false。
//    - 递归比较 p->left 与 q->right，且 p->right 与 q->left，两者都为 true 时返回 true。
// 2. isSymmetric(root) 调用 isMirror(root->left, root->right)，根为空则返回 true。
// 3. 用该镜像比较替换原来错误的 isSameTree 比较（原比较是逐节点相同而非镜像相同）。
// 这样能正确判断二叉树是否关于根对称（镜像对称）。
class Solution {
public:
    // 比较两棵树是否互为镜像
    bool isMirror(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr)
            return p == q;
        if (p->val != q->val)
            return false;
        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isMirror(root->left, root->right);
    }
};
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr)
            return p == q;
        return p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->left, q->right);

    }
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left, root->right);
    }
};
class Solution {
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            return p == q;
        }
        return p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left, root->right);
    }
};

class Solution {
public:
    int hight(TreeNode* p)
    {
        if (p == nullptr)
            return 0;
        return max(hight(p->left), hight(p->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        return abs(hight(root->left) - hight(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    class Solution {
    public:
        int xorOperation(int n, int start) {
            vector<int> v;
            int i = 0, ans = 0;
            while (n--)
            {
                v.push_back(start + 2 * i);
                i++;
            }
            for (int e : v)
                ans ^= e;
            return ans;
        }
    };