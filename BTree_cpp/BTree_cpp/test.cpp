#define _CRT_SECURE_NO_WARNINGS 
using namespace std;
#include<iostream>
template<class K>
struct BTreeNode
{
	BTreeNode<K>* _left;
	BTreeNode<K>* _right;
	K _key;
	BTreeNode(const K&key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{ }
	
};
template<class K>
class BTree
{
public:
	
	BTree()
		:_root(nullptr)
	{ }
	typedef BTreeNode<K> Node;
	bool insrt(const K& val)
	{
		
		if (_root == nullptr)
		{
			Node *cur= new Node(val);
			_root = cur;
			return true;
		}
		Node* cur = _root;
		Node* parent = _root;
		while(cur)
		{
			if (cur->_key > val)
			{
				 parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < val)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		 cur = new Node(val);
		 if (parent->_key <val)
			 parent->_right = cur;
		 else
			 parent->_left = cur;
		 return true;
	}
	void _InOrder(Node* root)
	{
		if (root==nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
	void InOrder()
	{
		_InOrder(_root);
	}
private:
	Node* _root;
};
int main()
{
	int a[] = { 1,2,4,5,6,8,9,78,45,62 };
	BTree<int> t1;
	for (auto e : a)
	{
		t1.insrt(e);
	}
	t1.InOrder();

	return 0;
}