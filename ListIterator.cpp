#include <iostream>
using namespace std;


//1¡¢Ä£ÄâÊµÏÖ¿âList
template<class T>
struct ListNode
{
	ListNode(const T& x = T())
		: _prev(0)
		, _next(0)
		, _value(x)
	{}

	ListNode<T>* _prev;
	ListNode<T>* _next;
	T _value;
};

template<class T, class Ref, class Ptr>
struct __ListIterator__
{
	typedef __ListIterator__<T, T&, T*> Iterator;
	typedef __ListIterator__<const T, const T&, const T*> ConstItrator;
	typedef __ListIterator__<T, Ref, Ptr> Self;
	typedef T ValueType;
	typedef Ref Reference;
	typedef Ptr Pointer;
	typedef ListNode<T>* LinkType;
	typedef size_t SizeType;

	LinkType _node;

	__ListIterator__(LinkType x)
		:_node(x)
	{}
	__ListIterator__()
	{}
	__ListIterator__(const Iterator& x)
		:_node(x._node)
	{}
	bool operator==(const Iterator& x)
	{
		return _node == x._node;
	}
	bool operator!=(const Iterator& x)
	{
		return _node != x._node;
	}
	Reference operator*()
	{
		return *(_node)._value;
	}
	Pointer operator->()
	{
		return &(operator*());
	}
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}
	Self operator++(int)
	{
		Self temp = *this;
		++*this;
		return temp;
	}
	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}
	Self operator--(int)
	{
		Self temp = *this;
		--*this;
		return temp;
	}
};

template<class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef T ValueType;
	typedef ValueType* Pointer;
	typedef const ValueType* ConstPointer;
	typedef ValueType& Reference;
	typedef const ValueType& ConstReference;
	typedef Node* LinkType;
	typedef size_t SizeType;
	typedef __ListIterator__<T, T&, T*> Iterator;
	typedef __ListIterator__<const T, const T& ,const T*> ConstIterator;

	List()
		:_node(new Node())
	{
		_node->_next = _node;
		_node->_prev = _node;
	}
	Iterator Begin()
	{
		return (*_node)._next;
	}
	ConstIterator Begin()const
	{
		return (*_node)._next;
	}
	Iterator End()
	{
		return _node;
	}
	ConstIterator End()const
	{
		return _node;
	}
	bool Empty()const
	{
		return _node == _node._next;
	}
	SizeType Size()const;
	Reference Front()
	{
		return *Begin();
	}
	ConstReference Front()const
	{
		return *Begin();
	}
	Reference Back()
	{
		Iterator temp = End();
		--temp;
		return *temp;
	}
	ConstReference Back()const
	{
		Iterator temp = End();
		--temp;
		return *temp;
	}
	Iterator Insert(Iterator pos, const T& x)
	{
		LinkType temp = new Node(x);
		temp->_next = pos._node;
		temp->_prev = pos._node->_prev;
		pos._node->_prev->_next = temp;
		pos._node->_prev = temp;
		return temp;
		
	}
	void PushFront(const T& x)
	{
		Insert(Begin(),x);
	}
	void PushBack(const T& x)
	{
		Insert(End(),x);
	}
	Iterator Erase(Iterator pos)
	{
		LinkType temp = pos._node->_next;
		pos._node->_prev->_next = pos._node->_next;
		pos._node->_next->_prev = pos._node->_prev;
		delete pos._node;
		pos._node = NULL;
		return temp;
	}
	void PopFront()
	{
		Erase(Begin());
	}
	void PopBack()
	{
		Erase((--End()));
	}
	void Clear()
	{
		while(End() != Begin())
		{
			Erase(Begin());
		}
		_node->_next = _node;
		_node->_prev = _node;
	}
	List(const List<T>& l)
	{
		_node = new Node();
		_node->_next = _node;
		_node->_prev = _node;
		ConstIterator it = l.Begin();
		while(it != l.End())
		{
			PushBack(*it);
			++it;
		}
	}
	List& operator=(const List& l)
	{
		_node = new Node();
		_node._next = _node;
		_node._prev = _node;
		ConstIterator it = l.Begin();
		while(it != l.End())
		{
			PushBack(*it);
			++it;
		}
		return (*this);
	}
	~List()
	{
		Clear();
	}
protected:
	LinkType _node;
};

void Funtest()
{
	List<int>l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushFront(5);
	List<int>::Iterator it = l.Begin();
	l.Insert(++it, 3);
	l.Erase(++it);
	//l.PopBack();
	//l.PopFront();
	//l.Insert()
	//l.Clear();
}

int main()
{
	Funtest();
	return 0;
}
