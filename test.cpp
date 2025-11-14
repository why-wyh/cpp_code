#define _CRT_SECURE_NO_WARNINGS 
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
    person(const char& name = '1')
        :_name(name)
    {};
private:
    char _name;
};
class student :person
{
public:
    student(const char p, int* a)
        :person(p)
        , _st(a)
    {
    };
private:
    int* _st;
};