#pragma once
namespace why {
	template<class T>
	struct __list_node
	{
		__list_node<T>* _prev;
		__list_node<T>* _next;
		T _data;
		__list_node()
			: _prev(nullptr), _next(nullptr), _data()
		{}
	};

	template<class T, class Ref = T&, class Ptr = T*>
	struct __list_iterator
	{
		typedef __list_node<T> Node;
		Node* _node;
		__list_iterator(Node* node = nullptr)
			: _node(node)
		{
		}
		Ref operator*() const
		{
			return _node->_data;
		}
		Ptr operator->() const
		{
			return &_node->_data;
		}
		__list_iterator& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		__list_iterator operator++(int)
		{
			__list_iterator tmp = *this;
			++(*this);
			return tmp;
		}
		__list_iterator& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		__list_iterator operator--(int)
		{
			__list_iterator tmp = *this;
			--(*this);
			return tmp;
		}
		bool operator==(const __list_iterator& it) const
		{
			return _node == it._node;
		}
		bool operator!=(const __list_iterator& it) const
		{
			return _node != it._node;
		}
	};

	template<class T>
	class list
	{
		typedef __list_node<T> Node;
	public:
		typedef __list_iterator<T,T&,T*>  iterator;
		typedef __list_iterator<T, const T&, const T*>  const_iterator;

		list()
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
			_head->_next = _head;
			_head->_prev = _head;
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		void push_back(const T& val)
		{
			/*Node* newnode = new Node;
			newnode->_data = val;
			Node* prev = _head->_prev;
			newnode->_prev = prev;
			newnode->_next = _head;
			prev->_next = newnode;
			_head->_prev = newnode;*/
			insert(end(), val);
		}
		void insert(iterator pos, const T& val)
		{
			Node* newnode = new Node;
			newnode->_data = val;
			Node* cur = pos._node;
			Node* prev = pos._node->_prev;
			prev->_next = newnode;
			newnode->_prev = prev;
			cur->_prev = newnode;
			newnode->_next = cur;
		}
		Node* erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			return next;
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		void push_front(const T& val)
		{
			insert(begin(), val);
		}
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
	    const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}
		void list_print()const
		{
			for (auto e : *this)
			{
				cout << e << " ";
			}
			cout << endl;
		}
		list(const list<T>& lt)
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
			for (auto e : lt)
				push_back(e);
		}
		list<T>& operator=(list<T>lt)
		{
			swap(_head, lt._head);
			return *this;

		}
	private:
		Node* _head;
	};

	void test1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		
		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		lt.push_front(0);
		lt.pop_back();
		lt.list_print();
		lt.pop_front();
		lt.list_print();
		auto lt2(lt);
		lt2.list_print();
	}
	void test2()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		list<int>lt2 = lt1;
		lt1.list_print();
		lt2.list_print();
		lt1.clear();
		lt1.list_print();


	}
}
