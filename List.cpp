#include <iostream>
using namespace std;

//作业名称：以C++方式实现链表

#pragma once
typedef int DataType;

struct Node
{
	Node(const DataType& data)
		: _data(data)
		, _pNext(NULL)
		, _pPre(NULL)
	{}

	DataType _data;
	Node* _pNext;
	Node* _pPre;
	Node* next;
};

class List
{
public:
	List(const DataType&data = DataType())
	{
		_pHead = new Node(data);
		_size = 1;
	}
	List(size_t n, const DataType& data = DataType())
	{
		size_t i= 0;
		Node* _pTemp = _pHead;
		_pTemp = new Node(data);
		_pTemp = _pTemp->_pNext;
		for(; i < n-1; ++i)
		{
			_pTemp = new Node(data);
			_pTemp = _pTemp->_pNext;
		}
		_size = n;
	}
	List(const List& l)
	{
		size_t i = 0;
		_pHead = NULL;
		_size = 0;
		for(; i < _size; ++i)
		{
			PushBack(l[i]._data);
		}
	}
	List& operator=(const List& l)
	{
		size_t i = 0;
		_pHead = NULL;
		_size = 0;
		for(; i < _size; ++i)
		{
			PushBack(l[i]._data);
		}
		return (*this);
	}
	~List()
	{
		Clear();
	}


	void PushBack(const DataType& data)
	{
		if(_pHead == NULL)
		{
			_pHead = new Node(data);
			_size = 1;
		}
		Node* _pTemp1 = new Node(data);
		Node* _pTemp2 = _pHead;
		while(_pTemp2->_pNext)
		{
			_pTemp2 = _pTemp2->_pNext;
		}
		_pTemp2->_pNext = _pTemp1; 
		_pTemp1->_pPre = _pTemp2;
		++_size;
	}
	void PopBack()
	{
		if(_pHead == NULL)
		{
			return ;
		}
		else if(_pHead->_pNext == NULL)
		{
			delete _pHead;
			_pHead = NULL;
			_size = 0;
		}
		else
		{
			Node* _pTemp1 = _pHead;
			while(_pTemp1->_pNext)
			{
				_pTemp1 = _pTemp1->_pNext;
			}
			_pTemp1->_pPre->_pNext = NULL;
			_pTemp1->_pPre = NULL;
			delete _pTemp1;
			_pTemp1 = NULL;
			--_size;
		}
	}
	void PushFront(const DataType& data)
	{
		if(_pHead == NULL)
		{
			_pHead = new Node(data);
			_size = 1;
		}
		else
		{
			Node* _pTemp = new Node(data);
			//_pTemp->_pNext = _pHead->_pNext;
			//_pHead->_pNext->_pPre = _pTemp;
			//_pHead->_pNext = _pTemp;
			//_pTemp->_pPre = _pHead;
			_pTemp->_pNext = _pHead;
			_pHead->_pPre = _pTemp;
			_pHead = _pTemp;
			++_size;
		}
	}
	void PopFront()
	{
		if(_pHead == NULL)
		{
			return;
		}
		else if(_pHead->_pNext =NULL)
		{
			delete _pHead;
			_pHead = NULL;
			_size = 0;
		}
		Node* _pTemp = _pHead;
		_pTemp = _pTemp->_pNext;
		_pTemp->_pPre = NULL;
		delete _pHead;
		_pHead = _pTemp;
		--_size;
	}
	void Insert(Node* pos, const DataType& data)
	{
		Node* _sTemp = new Node(data);
		if(pos->_pNext == NULL)
		{
			pos->_pNext = _sTemp;
			_sTemp->_pPre = pos;
			_sTemp->_pNext = NULL;
			++_size;
		}
		else
		{
			//_sTemp->_pNext = pos->_pNext;
			//pos->_pNext->_pPre = _sTemp;
			//_sTemp->_pPre = pos;
			//pos->_pNext = _sTemp;
			//++_size;
			pos->_pPre->_pNext = _sTemp;
			_sTemp->_pPre = pos->_pPre;
			pos->_pPre = _sTemp;
			_sTemp->_pNext = pos;
			++_size;
		}
		
	}
	void Erase(Node* pos)
	{
		if(pos == NULL)
		{
			return ;
		}
		else if(pos == _pHead)
		{
			_pHead = pos->_pNext;
			_pHead->_pPre = NULL;
			delete pos;
			pos = NULL;
			--_size;
		}
		else if(pos->_pNext == NULL)
		{
			pos->_pPre->_pNext = NULL;
			pos->_pPre = NULL;
			delete pos;
			pos = NULL;
			--_size;
		}
		else
		{
			pos->_pPre->_pNext = pos->_pNext;
			pos->_pNext->_pPre = pos->_pPre;
			pos->_pPre = NULL;
			delete pos;
			pos = NULL;
			--_size;
		}
	}
	void Assign(size_t n, const DataType data = DataType())
	{
		while (n--)
		{
			PushFront(data);
		}
	}
	void Clear()
	{
		Node* _sTemp = NULL;
		while(_pHead)
		{
			_sTemp = _pHead;
			_pHead = _pHead->_pNext;
			delete _sTemp;
			_sTemp = NULL;
			--_size;
		}
	}

	Node& Front()
	{
		return (*_pHead);
	}
	const Node& Front()const
	{
		return (*_pHead);
	}
	Node& Back()
	{
		Node* _sTemp = _pHead;
		while(_sTemp->_pNext)
		{
			_sTemp = _sTemp->_pNext;
		}
		return *_sTemp;
	}
	const Node& Back()const
	{
		Node* _sTemp = _pHead;
		while(_sTemp->_pNext)
		{
			_sTemp = _sTemp->_pNext;
		}
		return *_sTemp;
	}
	Node& operator[](size_t index)
	{
		Node* _sTemp = _pHead;
		size_t i = 0;
		for(; i < index; ++i)
		{
			_sTemp = _sTemp->_pNext;
		}
		return (*_sTemp);
	}
	const Node& operator[](size_t index)const
	{
		Node* _sTemp = _pHead;
		size_t i = 0;
		for(; i < index; ++i)
		{
			_sTemp = _sTemp->_pNext;
		}
		return (*_sTemp);
	}
	size_t Size()const
	{
		return _size;
	}
	bool Empty()const
	{
		if(_pHead == NULL)
			return false;
		return true;
	}
private:
	Node* _pHead;
	Node* _pTail;
	size_t _size;
};



void Funtest()
{
	List l(4);
	//l.Assign(4,5);
	//List& operator =(const List&l);
	//l.PushBack(1);
	//l.PushBack(2);
	//l.PushBack(3);
	//l.PopBack();
	//l.PopBack();
	//l.PopBack();
	//l.PopBack();
	////l.PushBack(4);
	l.PushFront(1);
	l.PushFront(2);
	l.PushFront(3);
	l.Insert(&l[1],4);
	l.Insert(&l[3],5);
	l.Insert(&l[2],6);
	l.Insert(&l[6],7);
	l.Erase(&l[1]);
	l.Erase(&l[2]);
	l.Erase(&l[5]);
	//List L;
	//L=l;
}

int main()
{
	Funtest();
	return 0;
}